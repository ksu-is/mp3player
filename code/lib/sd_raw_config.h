
/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef SD_RAW_CONFIG_H
#define SD_RAW_CONFIG_H

/**
 * \addtogroup sd_raw
 *
 * @{
 */
/**
 * \file
 * MMC/SD support configuration.
 */

/**
 * \ingroup sd_raw_config
 * Controls MMC/SD write support.
 *
 * Set to 1 to enable MMC/SD write support, set to 0 to disable it.
 */
#define SD_RAW_WRITE_SUPPORT 1

/**
 * \ingroup sd_raw_config
 * Controls MMC/SD write buffering.
 *
 * Set to 1 to buffer write accesses, set to 0 to disable it.
 *
 * \note This option has no effect when SD_RAW_WRITE_SUPPORT is 0.
 */
#define SD_RAW_WRITE_BUFFERING 1

/**
 * \ingroup sd_raw_config
 * Controls MMC/SD access buffering.
 * 
 * Set to 1 to save static RAM, but be aware that you will
 * lose performance.
 *
 * \note When SD_RAW_WRITE_SUPPORT is 1, SD_RAW_SAVE_RAM will
 *       be reset to 0.
 */
#define SD_RAW_SAVE_RAM 1

/* defines for customisation of sd/mmc port access */
#define CS (1 << 7)
#define configure_pin_mosi() PINSEL0 |= (1 << 12)
#define configure_pin_sck() PINSEL0 |= (1 << 8)
#define configure_pin_ss() IODIR0 |= CS
#define configure_pin_miso() PINSEL0 |= (1 << 10)

#define select_card() IOCLR0 |= CS;
#define unselect_card() IOSET0 |=CS;

#define configure_pin_available() IODIR0  &= ~(CS)
#define configure_pin_locked() if(1)

#define get_pin_available() (!((IOPIN0&CS)>>7))
#define get_pin_locked() (0)

/**
 * @}
 */

/* configuration checks */
#if SD_RAW_WRITE_SUPPORT
#undef SD_RAW_SAVE_RAM
#define SD_RAW_SAVE_RAM 0
#else
#undef SD_RAW_WRITE_BUFFERING
#define SD_RAW_WRITE_BUFFERING 0
#endif

#endif

