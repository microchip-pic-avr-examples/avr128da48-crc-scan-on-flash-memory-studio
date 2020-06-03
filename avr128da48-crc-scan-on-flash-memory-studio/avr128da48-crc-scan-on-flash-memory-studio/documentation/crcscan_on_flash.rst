CRCSCAN on Flash memory using AVR DA
=====================================

Introduction
============

This example demonstrates usage of Cyclic Redundancy Check Memory Scan (CRCSCAN) peripheral to perform CRC operation on the Flash memory and Nonvolatile Memory Controller (NVMCTRL) peripheral to perform read and write operations on the Flash memory in runtime.

Note :This example could be generated with all the pin variants of AVR DA family of microcontrollers.


Demo Description
================

In this example the application program is loaded into the APPCODE section of the Flash. Pre-calculated CRC checksum is stored in the last section of the Flash memory. The CRC checksum is calculated periodically for the whole Flash memory using CRCSCAN peripheral and is compared with the pre-calculated CRC checksum. Depending on the comparison result, the corresponding CRCSCAN status is printed on the terminal window. Upon switch press event, data stored in APPDATA section of the Flash is inversed, which result in a failure to the subsequent CRC checksum calculations and LED turns ON.

Video of the demo is available here: https://youtu.be/Z_syAVUn_zY

For more details about the example and configuration details in Studio IDE, refer the example posted on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-crc-scan-on-flash-memory-studio.git

This example is also generated using MPLAB X IDE  and is available on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-crc-scan-on-flash-memory-mplab.git

Supported evaluation kit
========================

*   `AVR128DA48 Curiosity Nano Evaluation Kit <https://www.microchip.com/developmenttools/ProductDetails/DM164151>`_

Note : Atmel Studio 7.0.2397 tool and AVR/GNU C Compiler is used for the development of this example

Prerequisites
==============
*	Configure BOOTSIZE and CODESIZE fuse to 0x2 and 0xFE, respectively to divide Flash memory in BOOT, APPCODE and APPDATA section. To configure these fuses using Atmel Studio IDE, navigate to *Tools->Device Programming->Fuses*, write 0x02 and 0xFE in value field of **BOOTSIZE** and **CODESIZE** respectively.
*   In same Fuse window, Select **CRCSEL** in **SYSCFG0** register to **Enable CRC 16** (In case of CRC-32, select **Enable CRC 32**). Select **CRCSRC** in **SYSCFG0** register to **CRC OF FULL FLASH**. Click on **Program**.
*   In this example, the application program is loaded into the APPCODE section of Flash memory. Navigate to *Project->Properties->Toolchain->AVR/GNU Linker->Memory Settings->Flash segment* Add **.text=0x200** in Flash segment section.
*	The pre-calculated CRC checksum must be stored at the end of the Flash memory. This is achieved using post build command. Navigate to *Project->Properties->Build Events->Post-build event command line*. Add following command for CRC-16,


+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+-----------+-----------+---------+
| srec_cat "$(OutputDirectory)\$(OutputFileName).hex" -intel  -fill 0xFF 0 0x1FFFE  -crop 0 0x01FFFE -CRC16_Big_Endian 0x1FFFE  -broken   -o "$(OutputFileName)_crc.hex" -intel -line-length=44   |                           
+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+-----------+-----------+---------+

For CRC-32 use following command

+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+-----------+-----------+---------+
| srec_cat "$(OutputDirectory)\$(OutputFileName).hex" -intel  -fill 0xFF 0 0x1FFFC  -crop 0 0x01FFFC -CRC32_Little_Endian 0x1FFFC  -ccitt   -o "$(OutputFileName)_crc.hex" -intel -line-length=44 |                         
+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+---------+---------+-----------+-----------+-----------+---------+

Complete command line description and options can be found here: http://srecord.sourceforge.net/man/man1/srec_input.html


Running the demo
================

*   In Atmel START web page, select **"EXPORT PROJECT"** tab and click **"Download Pack"** to save the .atzip file.
*	Import .atzip file to Atmel Studio 7 IDE (*File->Import->Atmel Start Project*).
*	Follow the steps mentioned in Prerequisites section.
*	Build Solution and make sure the build is successful without any errors.
*	Program AVR128DA48 by clicking *Tools->Device programming->(Tool=mEDBG, Device=ATtiny817, Interface=UPDI, Apply)-> Memories ->Program and select <project_name>_crc.hex*. 
*	Open Standalone Data Visualizer. Select Virtual COM Port to which AVR DA nano board is connected. Click **Connect**. 
*	Press the Switch (SW0) to toggle the data present in APPDATA section. Observe the messages on terminal window and LED (LED0) state.  

**Note:**

Hex file generated by Atmel Studio does not contain fuse information, thus fuses needs to be programmed separately. To make production file with fuse setting included, follow the steps mentioned below.

*	Navigate to *Tools->Device programming->(Tool=nEDBG, Device=AVR128DA48, Interface=UPDI, Apply)->Production file->(In Save to ELF production file section->In Flash tab)->select <project_name>_crc.hex* file->tick the **Flash** and **Fuses** checkbox->click on **Save**->save the <file_name> with .elf extension.  This .elf file contain fuse information also.
*	Program the generated production file (.elf) in last step to AVR128DA48 by clicking on *Tools->Device programming window->Production file->Program device from ELF production file section*->browse the saved *.elf*  file and tick the **Flash** and **Fuses** checkbox and click on **Program**.



