# Automatic MicroSD-to-USB Backup Device

An automated, standalone hardware solution based on the **Seeed Studio XIAO ESP32-S3** designed to automatically back up all files from a MicroSD card directly to a USB flash drive upon card insertion.

## Features

* **Automatic Detection:** MicroSD insertion triggers the backup process using an active-low Card Detect pin (`DET`).
* **High-Speed Transfer:** Uses native 4-bit SDMMC mode for fast read speeds from the MicroSD card.
* **Power Efficient:** Dynamically enables the onboard 5V boost converter (TPS61230) to supply power to the USB Host port only during backup operations.
* **Reverse Polarity Protection:** Integrated P-MOSFET (DMG2305UX) safeguards the board during battery power supply.

## Hardware Components

* **MCU:** Seeed Studio XIAO ESP32-S3
* **Power Management:** TPS61230 5V Boost Converter (controlled via GPIO Pin `D10`)
* **Reverse Polarity Protection:** DMG2305UX P-MOSFET
* **Storage:** MicroSD Slot (Push-Push with Card Detect) & USB-A Host Socket
