#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

#define PAGE_SIZE (512)
#define LED_ON() LED0_set_level(false)
#define LED_OFF() LED0_set_level(true)

const flash_adr_t crcStoredAddressMSB = 0X1FFFE; // Address at which pre-calculated crc MSB is stored for 16-bit CRC
const flash_adr_t crcStoredAddressLSB = 0X1FFFF; // Address at which pre-calculated crc LSB is stored for 16-bit CRC
const flash_adr_t appDataAddress      = 0x1FC01; // Address at which data will be toggled in AppData section

// Uncomment this for 32-bit CRC and comment 16-bit CRC
/* const flash_adr_t crcStoredAddress0 = 0x1FFFC; //Address at which crc LSB is stored
 const flash_adr_t crcStoredAddress1 = 0x1FFFD; //Address at which crc 2nd byte is stored
 const flash_adr_t crcStoredAddress2 = 0x1FFFE; //Address at which crc 3rd byte is stored
 const flash_adr_t crcStoredAddress3 = 0x1FFFF; //Address at which crc MSB is stored */

volatile uint8_t switchPressInterruptFlag;
volatile uint8_t pitInterruptFlag;
uint16_t         preCalculatedCRC0;
uint16_t         preCalculatedCRC1;
uint8_t byteToBeWritten = 0XFF;           // Data to be written in the flash in runtime
uint8_t flashPageBuffer[PAGE_SIZE] = {0}; // A buffer in memory the size of a flash page, used as a scratch pad

void ApplicationTask(void);
void StartCrcScan(void);

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	printf("\rSystem Initialized\n");

	// Read pre-calculated crc stored at two last two bytes of the Flash memory for 16-bit CRC
	preCalculatedCRC0 = FLASH_0_read_flash_byte(crcStoredAddressMSB);
	preCalculatedCRC0 |= (FLASH_0_read_flash_byte(crcStoredAddressLSB)) << 8;

	// Uncomment this to read pre-calculated crc stored at last four bytes of the Flash memory for 32-bit CRC
	// Comment 16-bit CRC ,  when 32-bit CRC is configured
	/*	preCalculatedCRC0 = FLASH_0_read_flash_byte(crcStoredAddress1);
	   preCalculatedCRC0 |= (FLASH_0_read_flash_byte(crcStoredAddress0)) << 8;
	   preCalculatedCRC1 |= (FLASH_0_read_flash_byte(crcStoredAddress3));
	   preCalculatedCRC1 |= (FLASH_0_read_flash_byte(crcStoredAddress2)) << 8; */

	printf("\rPre-calculated CRC read from Flash is complete\n");

	// Read 16-bit pre-calculated CRC
	printf("\rPre-calculated CRC: 0x%04X\n", preCalculatedCRC0);

	// Uncomment this to read 32-bit CRC and comment 16-bit CRC printf statement
	// printf("\rPre-calculated CRC: 0x%04X%04X\n", preCalculatedCRC0, preCalculatedCRC1);

	/* Replace with your application code */
	while (1) {
		ApplicationTask();
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  This function checks whether the pre-calculated crc matches with the calculated crc or not and displays the status.
  **/
void ApplicationTask(void)
{
	if (pitInterruptFlag) {
		// Start crc scan of whole Flash memory
		StartCrcScan();

		// CRC scan is successful
		if (CRCSCAN_STATUS & CRCSCAN_OK_bm) {
			LED_OFF();

			// To display for 16-bit CRC
			printf("\rCRC matched with the pre-calculated CRC:0x%04X\n", preCalculatedCRC0);

			// Uncomment this To display 32-bit CRC and comment 16-bit CRC
			// printf("\rCRC matched with the pre-calculated CRC:0x%04X%04X\n", preCalculatedCRC0, preCalculatedCRC1);
		}

		// CRC scan is failed
		else {
			LED_ON();

			// To display for 16-bit CRC
			printf("\rCRC did not match with the pre-calculated CRC:0x%04X\n", preCalculatedCRC0);

			// Uncomment this To display 32-bit CRC and comment  16-bit CRC
			// printf("\nCRC did not match with the pre-calculated CRC:0x%04X%04X\n", preCalculatedCRC0,
			// preCalculatedCRC1);
		}

		// Clear periodic interrupt flag
		pitInterruptFlag = 0;
	}

	if (switchPressInterruptFlag) {
		// Toggle byte between 0x00 and 0xFF
		byteToBeWritten = ~(byteToBeWritten);

		// Write byteToBeWritten at appDataAddress
		FLASH_0_write_flash_byte(appDataAddress, flashPageBuffer, byteToBeWritten);

		printf("\r0x%02X is written at 0x%lX in APPDATA section of Flash\n", byteToBeWritten, appDataAddress);

		// Clear flag which is set at the switch press event
		switchPressInterruptFlag = 0;
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  This function enables crc peripheral and waits until crcscan of whole flash memory is complete.
  **/
void StartCrcScan(void)
{
	printf("\rStarted CRC Scan..");

	// Enable CRC scan: enabled
	CRCSCAN.CTRLA = 1 << CRCSCAN_ENABLE_bp;

	// Wait for CRCSCAN to complete
	while ((CRCSCAN.STATUS & CRCSCAN_BUSY_bm))
		;
}
