#include <Arduino.h>
#include <FS.h>
#include <SD_MMC.h>
#include <UsbHostMsc.h>

#define PIN_SD_DET   1
#define PIN_BOOST_EN 11

#define PIN_SD_CLK   7
#define PIN_SD_CMD   8
#define PIN_SD_D0    9
#define PIN_SD_D1    4
#define PIN_SD_D2    5
#define PIN_SD_D3    6

UsbHostMsc USBHost;

volatile bool sdInserted = false;

void IRAM_ATTR sdCardISR() {
    sdInserted = (digitalRead(PIN_SD_DET) == LOW);
}

void powerBoost(bool enable) {
    digitalWrite(PIN_BOOST_EN, enable ? HIGH : LOW);
    if (enable) {
        delay(150);
    }
}

bool mountSDCard() {
    SD_MMC.setPins(PIN_SD_CLK, PIN_SD_CMD, PIN_SD_D0, PIN_SD_D1, PIN_SD_D2, PIN_SD_D3);

    if (!SD_MMC.begin("/sd", false)) {
        return false;
    }
    return true;
}

void copyFiles(File sourceDir) {
    while (true) {
        File entry = sourceDir.openNextFile();
        if (!entry) break;

        String entryPath = String(entry.path());
        String destPath = "/usb" + entryPath;

        if (entry.isDirectory()) {
            mkdir(destPath.c_str(), 0777);
            copyFiles(entry);
        } else {

            File sourceFile = SD_MMC.open(entryPath.c_str(), FILE_READ);
            FILE* destFile = fopen(destPath.c_str(), "wb");

            if (sourceFile && destFile) {
                uint8_t buffer[4096];
                while (sourceFile.available()) {
                    size_t bytesRead = sourceFile.read(buffer, sizeof(buffer));
                    fwrite(buffer, 1, bytesRead, destFile);
                }
                fclose(destFile);
            } else {
            }

            if (sourceFile) sourceFile.close();
        }
        entry.close();
    }
}

void processBackup() {
    powerBoost(true);

    if (!mountSDCard()) {
        powerBoost(false);
        return;
    }

    
    if (!USBHost.begin("/usb")) {
        SD_MMC.end();
        powerBoost(false);
        return;
    }

    File root = SD_MMC.open("/");
    if (root) {
        copyFiles(root);
        root.close();
    }

    USBHost.end();
    SD_MMC.end();
    powerBoost(false);

    
}

void setup() {
    Serial.begin(115200);

    pinMode(PIN_BOOST_EN, OUTPUT);
    powerBoost(false);

    pinMode(PIN_SD_DET, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_SD_DET), sdCardISR, CHANGE);

    if (digitalRead(PIN_SD_DET) == LOW) {
        sdInserted = true;
    }
}

void loop() {
    if (sdInserted) {
        delay(200);
        if (digitalRead(PIN_SD_DET) == LOW) {
            processBackup();

            while (digitalRead(PIN_SD_DET) == LOW) {
                delay(500);
            }
        }
        sdInserted = false;
    }

    delay(100);
}