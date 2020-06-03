/**
 * \file
 *
 * \brief CRCSCAN related functionality implementation.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_crcscan_init CRCSCAN Init Driver
 * \ingroup doc_driver_crcscan
 *
 * \section doc_driver_crcscan_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <crcscan.h>

/**
 * \brief Initialize crcscan interface
 * \return Status
 */
int8_t CRC_0_init(void)
{

	// CRCSCAN.CTRLB = CRCSCAN_SRC_FLASH_gc; /* CRC on entire flash */

	// CRCSCAN.CTRLA = 0 << CRCSCAN_ENABLE_bp /* Enable CRC scan: disabled */
	//		 | 0 << CRCSCAN_NMIEN_bp; /* Enable NMI Trigger: disabled */

	return 0;
}
