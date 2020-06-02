<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# CRC SCAN ON FLASH MEMORY
  
Cyclic Redundancy Check Memory Scan (CRCSCAN) peripheral  is a Core Independent Peripheral (CIP) which can be configured to run without any intervention from the CPU after initialization. CRCSCAN peripheral is used to detect faults in the target section of the Flash and to ensure no code corruption has occurred in Flash memory. This example demonstrates usage of CRCSCAN peripheral to perform CRC operation on the Flash memory and Nonvolatile Memory Controller (NVMCTRL) peripheral to perform read and write operations on the Flash memory in runtime.

**Note:**

**1.	 This example could be generated with all the pin variants of AVR DA family of microcontrollers.**

**2.	 This example is also generated using MPLAB X IDE and is available on GitHub at this location : https://github.com/microchip-pic-avr-examples/avr128da48-crc-scan-on-flash-memory-mplab.git

## Useful Links

- [AVR128DA48 Product Page](https://www.microchip.com/wwwproducts/en/AVR128DA28 "AVR128DA48 Product Page")
- [AVR128DA48 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=avr128da48 "AVR128DA48 Code Examples on GitHub")
- [AVR128DA48 Project Examples in START](https://start.atmel.com/#examples/AVR128DA48CuriosityNano "AVR128DA48 Project Examples in START")
- [CRC SCAN ON FLASH MEMORY - MPLAB Example](https://github.com/microchip-pic-avr-examples/avr128da48-crc-scan-on-flash-memory-mplab.git "CRC SCAN ON FLASH MEMORY - MPLAB Example")
- [Srec_cat](http://srecord.sourceforge.net/man/man1/srec_input.htmlhttp:/srecord.sourceforge.net/man/man1/srec_input.html "Srec_cat")

# Demo Description

***Fig 1:Block diagram view of the system used for CRCSCAN on Flash memory***

<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/QRyYNe9.jpg">
</p>

In this example,
* Srec_cat tool which comes with Studio IDE is used to pre-calculate CRC checksum and to store the calculated checksum in specific address of Flash. Pre-calculated CRC checksum is stored in the last section of the Flash memory.
	* **Note :**  For 16-bit CRC, two bytes checksum is generated and stored at the address 0x1FFFE and 0x1FFFF.
        * For 32-bit CRC, four bytes checksum is generated and stored at the address 0x1FFFC to 0x1FFFF.
* Flash memory is divided into three sections : Boot Code section, Application Code section and Application Data section. In this example the application program is loaded into the APPCODE section of the Flash memory and starts at the address 0x00400.
* The CRCSCAN can be set up to scan the entire Flash, only the boot section, or both the boot and application code sections. In this example CRCSCAN is set up to scan the whole Flash memory .
* The CRC is calculated periodically for the whole Flash memory using CRCSCAN peripheral and is compared with the pre-calculated CRC value. 
* Depending on the comparison result, the corresponding CRCSCAN status is printed on the terminal window. 
* Upon switch press event, one-byte data is written into the APPDATA section of the Flash memory at the address 0x1FC01 using NVMCTRL peripheral, which results to CRC failure in subsequent CRC scan and LED turns ON.
* Nonvolatile Memory Controller (NVMCTRL) peripheral is used to perform read and write operation on Flash memory in runtime.
***Note : This example could be generated with all the AVR DA family of MCUs.***


## To see the CRC SCAN on Flash memory demo operation video, click on the below image.


<a href="http://www.youtube.com/watch?feature=player_embedded&v=MuXe_AXPpC4
" target="_blank"><img src="https://i.imgur.com/fQ9DhZV.jpg"
alt="IMAGE ALT TEXT HERE" width="500" height="300" border="10" /></a>  

## Application Code Flow Diagram

***Fig 2 : Application Code Flow diagram***

<p align="center">
  <img width=auto height=auto src="images/firmware-flowchart.png">
</p>

## Software Used
- [MPLAB X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide "MPLAB X IDE v5.40")
- [XC8 Compiler v2.20](https://www.microchip.com/mplab/compilers "XC8 Compiler v2.20")
- [MPLAB Code Configurator (MCC) v3.95.0](https://www.microchip.com/mplab/mplab-code-configurator "MPLAB Code Configurator (MCC) v3.95.0")
- AVR8bit Lib v2.2.2
- AVR-Dx DFP 1.1.40
- [Standalone Data Visualizer v2.20.674](https://www.microchip.com/mplab/avr-support/data-visualizer "Standalone Data Visualizer v2.20.674")

**Note:** *For running the demo, the installed tool versions should be same or later.*

## Hardware used
[AVR128DA48 Curiosity Nano Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164151 "AVR128DA48 Curiosity Nano Evaluation Kit")

***Fig 3 : AVR128DA48 Curiosity Nano Evaluation Kit***

<p align="center">
  <img width=auto height=auto src="images/firmware-flowchart.png">
</p>

# Hardware setup

Connect AVR128DA48 Curiosity Nano board to Host Computer (PC) using standard micro B USB cable.

## Device Programming section

1.	Open Atmel Studio.
2.	Open the CRCSCAN on Flash Memory project. (File->Open Project).
3.	The pre-calculated CRC checksum using Srec_cat tool (which is a part of the Studio IDE) is stored at the end of the Flash memory. This is achieved by adding the following command in **post-build command section** of the project in Atmel Studio IDE. To open build event command line window, navigate to **“Project->Properties->Build Events->Post-build event command line”** as shown in Fig 4 . For more details about the post-build command, refer post-build command explanation section below.

***Fig 4 : Post-build event command line window for 16-bit CRC***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

**Note** : For 32-bit CRC use the following post-build command.
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>
4.	In this example the application program is loaded into the APPCODE section. This is achieved by adding command **“.text=0x200”** value in Flash segment section of the project in Atmel Studio IDE. To open Flash segment window, navigate to **“Project->Properties->Toolchain->AVR/GNU Linker->Memory Settings->Flash segment”** as shown in Fig 5.

Command : 
This command keeps the application code at 0x400 location in the Flash memory. It is the start address of APPCODE section of Flash.
***Fig 5 : Memory settings window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

5.	Build the solution by clicking on ![](https://i.imgur.com/ggqjWKi.jpg) **Build** icon and make sure build is successful without any errors.
6.	Go to Fuses tab and Configure **CRCSEL** bit in **SYSCFG0** register to **Enable CRC16** and **CRCSRC** bit in **SYSCFG0** register to **CRC OF FULL FLASH**  as shown in Fig 6 and click on **Program** . 
Note : For 32-bit CRC , Configure **CRCSEL** bit in **SYSCFG0** register to **Enable CRC32**.

***Fig 6 : Fuses configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

7.	Go to Tools -> Device Programming.
8.	Select the Tool and click Apply as shown in Fig 7.
***Fig 7 : Tool selecting window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

9.	Go to Production file tab and browse the _crc.hex file from the project folder by clicking on browse(…) button in Flash as shown in Fig 8. Check the Flash and Fuses option and click on Save button.
***Fig 8 : Device programming window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

10.	Save As window pops up , enter the file name, for example : crc16 saved in .elf format as shown in Fig 9 , which includes Fuses configuration in this file.
***Fig 9 : Save As window ***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

11.	Go to Production file tab and browse the crc16.elf file ,which is saved in Debug folder of the project by clicking on browse(…) option as shown in Fig 10. Check the Flash and Fuses option and click on Program button.
***Fig 10 : Device programming window ***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VTxQJZC.jpg">
</p>

# Demo Operation:

1.	Open Standalone Data Visualizer. Select Virtual COM Port to which AVR DA Curiosity Nano board is connected as shown in Fig 11. Click on Connect. 

Note : Alternately, open the Data Visualizer plugin extension available to Studio IDE.  

***Fig 11 : Standalone Data Visualizer window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/YCit6iU.jpg">
</p>

2 .Once programming is completed, terminal window starts displaying the messages as shown in Fig 12.

***Fig 12 : Initial status on Terminal window.***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

3.CRCSCAN starts after 8 sec. Status is printed on terminal window as shown in Fig 13.

***Fig 13 : CRCSCAN status on Terminal window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

3. Press Switch (SW0) to change a byte at location “0x1FC01”in the Flash memory to 0x00 as shown in Fig 14.

***Fig 14 : Switch press event***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

4.	Subsequent CRC scan will result in a CRC failure as shown in Fig 15 and LED0 on AVR DA Curiosity Nano board turns ON.

***Fig 15 : Subsequent scan result on Terminal window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

5.	Press Switch (SW0) again to change data back to 0XFF, at location “0x1FC01”in the Flash memory as shown in Fig 16.

***Fig 16 : Switch press event***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

6.	Subsequent CRC scan will result in CRC success as shown in Fig 17 and LED0 on AVR DA Curiosity Nano board turns OFF.

***Fig 17 : Subsequent scan result on terminal window***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

**Note:** Clean the project before programming the   _crc.hex file as explained in Device Programming section.

## Post build command explanation

### Post-build command for 16-bit CRC
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

This post build command takes the generated HEX file ($(OutputDirectory)\$(OutputFileName).hex) and fills the remaining space of Flash with 0xFF    (-fill 0xFF 0 0x1FFFE) . The “CRC16_Big_Endian” polynomial is used which generates a 16-bit CRC checksum of the data, stored in big-endian order at the specified address starts at 0x1FFFE. “-broken” option is a common-but-broken calculation is performed and the initial seed is 0x84CF. “-crop” option is used to isolate a particular section of the data and discard the rest.”-intel” option says to use the Intel hex format to read the hex file. The _crc.hex file is generated , where calculated CRC checksum is appended at the specified address of the Flash ( CRC checksum is stored at location 0x1FFFE and 0x1FFFF in Flash). 
Complete command line description and options can be found here: 

### Post-build command for 32-bit CRC
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/uRBeLAb.jpg">
</p>

# Summary : 

This example demonstrates how CRCSCAN peripheral can be used to perform integrity check on Flash memory. It also demonstrates use of NVMCTRL peripheral to perform read and write operations on Flash memory in run time. Appendix  section explains more about firmware generation using START used for this example., Frequency meter, DC motor control etc.


# Appendix : Atmel | START Project creation

Configure Timer, Event system, GPIO, RTC, USART peripherals  through Atmel|START code configurator and generate Atmel Studio project. 

Follow the below steps to generate the project using Atmel|START.

1.	Open **Atmel Studio 7**.
2.	Go to **File → New** and click on **Atmel Start Project** option.
3.	The **CREATE NEW PROJECT** window appears within Atmel Studio 7. In the **"Filter on device..."** text box, enter **AVR128DA48**, then select **AVR128DA48 Curiosity Nano** from the list and then click on **CREATE NEW PROJECT**, as shown below. Wait until project creation is completed.

***Fig 7 : Create New Project***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/rUuNAQ0.jpg">
</p>

4.	After project creation, **MY SOFTWARE COMPONENTS** window opens. 
* Open **PINMUX** configuration by clicking on ![](https://i.imgur.com/ggqjWKi.jpg) icon in the navigation tab, located on the left side of the window.
* Configure I/O pin **PA6** as input as shown in the Fig 8. The frequency and duty cycle of the input pulse signal to be measured is fed to the I/O pin PA6.

***Fig 8 : PINMUX Configuration pin PA6***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/jC5Rdqm.jpg">
</p>

5.	Add **Timer B, Event system, USART and RTC** components to the project
* Click ![](https://i.imgur.com/PXgXvRm.jpg) icon in the navigation tab, located on the left side of the window. Then, open the ADD SOFTWARE COMPONENTS window by clicking ![](https://i.imgur.com/AFqwPll.jpg) icon.
* Expand Drivers by clicking + icon.
* To add components to the project, select Timer , Event System, RTC, USART and click on ![](https://i.imgur.com/dA4nv4t.jpg) icon.
* Add the respective drivers to the project by clicking the Add component(s).

***Fig 9 :  ADD SOFTWARE COMPONENTS***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/pPU5ykh.jpg">
</p>

6.	Open the **CLOCK CONFIGURATOR** window by clicking ![](https://i.imgur.com/TOX2iTj.jpg) CLOCKS icon in the navigation tab, located at the left side of the window as shown in the Fig 10.

***Fig 10 : CLOCK configurator***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/CI8Fpk0.jpg">
</p>

* Configure the **Internal high-frequency oscillator** by clicking **CLOCK SETTINGS** ![](https://i.imgur.com/Q76XwcD.jpg) icon as shown in the Fig 10.
* By default, Internal high-frequency oscillator is configured to 4MHz frequency. Set the **Frequency Select** to **24** from the dropdown menu, which generates 24MHz frequency as shown in Fig 11.

***Fig 11 : CLOCK settings***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/xdL7Hq6.jpg">
</p>

## Timer B configuration:
 Timer B is a 16-bit Timer which is configured in Input Capture Frequency and Pulse-Width measurement mode and it is used to measure the period and pulse-width of the input signal. In this mode, the timer will start counting when a positive edge is detected on the event channel connected to the pin PA6. 
 Configure the TIMER_0 module by following the steps  as shown in the Fig 12. 
* Open the configuration window for TIMER by clicking on **TIMER_0**.
* Select **Drivers: TCB: Init** option from the dropdown menu against the Driver field, which selects Timer/Counter type B peripheral.
* Select **TCB2** option from the dropdown menu against the Instance field.
* Check the Enable option to enable the TCB2 module.
* Select **CLK_PER** option from the dropdown menu against the CLKSEL: Clock Select field, which uses 24MHz system clock as a clock source for this peripheral.
* Select **Input Capture Frequency and Pulse-Width measurement** mode option from the dropdown menu against the CNTMODE: Timer Mode field, which captures period and pulse-width value of the input signal.
* Check the **CAPT: Capture or Timeout** option to generate the capture interrupt. The capture interrupt flag is generated after capturing the period and pulse-width of the input signal.
* Check the **CAPTEI: Event Input Enable** option to enable the timer to start counting when it detects rising edge on the event channel connected to the pin PA6.

***Fig 12 : Timer B configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/cKjgJsP.jpg">
</p>

## Event system configuration: 
In this example, event system is used to connect the pin PA6 to the TCB2 through channel 0. The frequency and duty cycle of the input signal to be measured can’t be given directly to the TCB2, is given to the pin PA6 through event channel to the timer module. 
Configure the Event system module by following the steps shown in the Fig 13. 
* In event generator, select **PORT A PIN6** option and drag the cursor to the **Connect user to event channel 0** option and from **Connect user to event channel 0** option, drag the cursor to the **Event Input Enable** option in TCB2.

***Fig 13 : Event system configurator***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/Rbed3bn.jpg">
</p>

## USART1 Configuration:
 USART1 is used to transmit the measured frequency and duty cycle data of the input signal to the terminal window. Configure the USART1 module by following the steps shown in the Fig 14.
* Select **Drivers: USART: Basic** option from the dropdown menu against the Driver field.
* Select **Async IRQ Mode** option from the dropdown menu against the Mode field.
* Select the **USART1** option from the dropdown menu against the Instance field.
* Select **PC0** as output from the dropdown menu against the TXD field.
* Check the **Transmitter: Enable** option, which allows the data to transmit through USART peripheral.
* Set the **Baud Rate** to **115200**.

***Fig 14 : USART configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/VETmPQQ.jpg">
</p>

## RTC configuration:
 In this example RTC is configured in PIT (Periodic Interrupt Timer) mode, which generates a periodic interrupt after every 32768 RTC Clock cycles (1 sec delay). The periodic interrupt is used as a trigger for the USART to display data on to the terminal window. Configure the RTC module by following the steps shown in the Fig 15.
* Select **Drivers: RTC: Init** option from the dropdown menu against the Driver field.
* Check the **PITEN: Enable** option to enable the periodic interrupt timer mode.
* Select the clock **Internal 32.768KHz oscillator** option from the dropdown menu against the **RTC Clock Source Selection** field, which uses 32.768 KHz oscillator as a clock source for the PIT mode.
* Select the period **RTC Clock Cycles 32768** option from the dropdown menu against the **PERIOD: Period** field, which generates 1 sec delay.
* Check the **PI: Periodic Interrupt** option to generate periodic interrupt after specified RTC clock cycles.

***Fig 15 : RTC configuration***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/zHlkewc.jpg">
</p>


## Global Interrupt Enable configuration:
To generate the interrupt, it is required to enable the Global Interrupt Enable bit in the Status register.
* Click on the icon next to **"Show system drivers"** option, as shown  in the Fig 16.

***Fig 16 : Show system drivers***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/9zGu2eY.jpg">
</p>

* Click the **CPUINT** and then select the checkbox, **CPU_SREG: Global Interrupt Enable**, as shown in the Fig 17.

***Fig 17 : Enable CPU_SREG***
<p align="center">
  <img width=auto height=auto src="https://i.imgur.com/3nL7Z27.jpg">
</p>























