# Bill of Materials (BOM)

**Project:** Automatic MicroSD-to-USB Copier  
**Target Board:** Seeed Studio XIAO ESP32-S3 Baseboard  

## Component Summary

| Ref | Qty | Value / Part | Description | Footprint | Datasheet / Link |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **J1** | 1 | Micro_SD_Card_Det | Push-Push MicroSD Socket with Card Detect Switch | `Connector_Card:microSD_HC_Molex_47219-2001` | [XKB XKTF-015-N](https://datasheet.lcsc.com/lcsc/2110151630_XKB-Connectivity-XKTF-015-N_C381082.pdf) |
| **J2** | 1 | USB_A | USB Type-A Host Connector (Horizontal Right Angle) | `Connector_USB:USB_A_Molex_67643_Horizontal` | [Molex 67643 Series](https://www.molex.com/) |
| **J3** | 1 | JST-PH 2-Pin | LiPo / Battery Input Connector (2.00mm Pitch) | `Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal` | [JST PH Connector](https://www.jst-mfg.com/) |
| **Q1** | 1 | DMG2305UX | P-Channel MOSFET (Reverse Polarity Protection) | `Package_TO_SOT_SMD:SOT-23` | [Diodes Inc. DMG2305UX](https://www.diodes.com/) |
| **U1** | 1 | XIAO ESP32-S3 | Seeed Studio XIAO ESP32-S3 Microcontroller | `Seeed_Studio_XIAO_Series:XIAO-ESP32-S3-SMD` | [Seeed Wiki](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) |
| **U2** | 1 | TPS61230DRC | High-Efficiency Synchronous Step-Up Converter (5V Boost) | `Package_SON:Texas_S-PVSON-N10_ThermalVias` | [TI TPS61230 Datasheet](http://www.ti.com/lit/ds/symlink/tps61232.pdf) |

---

## Detailed KiCad Attributes

```csv
"Reference","Qty","Value","DNP","Exclude from BOM","Exclude from Board","Exclude from Simulation","Exclude from Position Files","Footprint","Datasheet"
"J1","1","Micro_SD_Card_Det1","","","","","${EXCLUDE_FROM_POS_FILES}","Connector_Card:microSD_HC_Molex_47219-2001","[https://datasheet.lcsc.com/lcsc/2110151630_XKB-Connectivity-XKTF-015-N_C381082.pdf](https://datasheet.lcsc.com/lcsc/2110151630_XKB-Connectivity-XKTF-015-N_C381082.pdf)"
"J2","1","USB_A","","","","","${EXCLUDE_FROM_POS_FILES}","Connector_USB:USB_A_Molex_67643_Horizontal",""
"J3","1","Conn_01x02_Pin","","","","","${EXCLUDE_FROM_POS_FILES}","Connector_JST:JST_PH_S2B-PH-K_1x02_P2.00mm_Horizontal",""
"Q1","1","Q_PMOS_GSD","","","","","${EXCLUDE_FROM_POS_FILES}","Package_TO_SOT_SMD:SOT-23",""
"U1","1","XIAO-ESP32-S3-SMD","","","","","${EXCLUDE_FROM_POS_FILES}","Seeed_Studio_XIAO_Series:XIAO-ESP32-S3-SMD",""
"U2","1","TPS61230DRC","","","","","${EXCLUDE_FROM_POS_FILES}","Package_SON:Texas_S-PVSON-N10_ThermalVias","[http://www.ti.com/lit/ds/symlink/tps61232.pdf](http://www.ti.com/lit/ds/symlink/tps61232.pdf)"
