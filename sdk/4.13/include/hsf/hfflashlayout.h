/* hfflashlayout.h
 *
 * Copyright (C) 2017 ShangHai High-flying Electronics Technology Co.,Ltd.
 *
 * This file is part of HSF.
 *
 */
 
#ifndef _HF_FLASH_LAYOUT_H_
#define _HF_FLASH_LAYOUT_H_


#define CONFIG_FLASH_SIZE_1MB
//#define CONFIG_FLASH_SIZE_2MB

#ifdef CONFIG_FLASH_SIZE_1MB

#define CONFIG_FLASH_SIZE					(1024*1024*1)

	#ifdef HF_OTA_SUPPORT
#define SYSTEM_SECTOR_ADDRESS				0x18000000
#define SYSTEM_SECTOR_SIZE					(0x1000)
#define BOOT_ADDRESS						0x18001000
#define BOOT_SIZE							(0x3000)
#define BOOT_CONFIG							0x18004000 
#define SOC_CONFIG_ADDRESS				0x18005000
#define SECU_FLASH_ADDR					0x18006000
#define USERPAGE 							0x18007000
#define USERPAGE_BACKUP 					0x18008000
#define F_SETTING_ADDRESS       				0x18009000
#define USER_BIN_FILE_OFFSET				0x1800A000
#define USER_BIN_FILE_MQTT_OFFSET		0x1800AB30     //size(1100) test by ZN ----20190610  
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x1800B000

#define SYSTEM_CONFIG_SIZE					(0x8000)

#define SOFTWARE_CODE_ADDRESS			0x1800C000
#define MAX_SOFTWARE_CODE_SIZE			(588*1024)
#define UPGRADE_ADDRESS					(SOFTWARE_CODE_ADDRESS+MAX_SOFTWARE_CODE_SIZE)
#define MAX_UPGRADE_FILE_SIZE				(372*1024)
#define UPGRADE_ADDRESS_END				(UPGRADE_ADDRESS+MAX_UPGRADE_FILE_SIZE)

	#else
#define BOOT_CONFIG							0x180C5000
#define USERPAGE 							0x180C6000
#define USERPAGE_BACKUP 					0x180C7000
#define F_SETTING_ADDRESS       				0x180C8000
#define SECU_FLASH_ADDR					0x180C9000
#define USER_BIN_FILE_OFFSET				0x180CA000
#define USER_BIN_FILE_MQTT_OFFSET		0x180CAB30     //size(1100) test by ZN ----20190610  
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x180CB000
#define SOC_CONFIG_ADDRESS				0x180CC000
#define SOFTWARE_CODE_ADDRESS			0x18001000
	#endif

#define WEB_ADDRESS						0x180FC000
#define WEB_ADDRESS_END					0x180FE000
#define WEB_SCAN_TMPBUF					0x0
#define HFUFLASH_SIZE						(4*1024)
#define HFUFLASH1_SIZE						(0*1024)
#define UFLASH_ADDRESS						0x180FE000
#define UFLASH1_ADDRESS					0x0
#define TEMP_FLASH_ADDRESS				0x180FF000

#elif defined(CONFIG_FLASH_SIZE_2MB)

#define CONFIG_FLASH_SIZE					(1024*1024*2)

	#ifdef HF_OTA_SUPPORT
#define SYSTEM_SECTOR_ADDRESS				0x18000000
#define SYSTEM_SECTOR_SIZE					(0x1000)
#define BOOT_ADDRESS						0x18001000
#define BOOT_SIZE							(0x3000)
#define BOOT_CONFIG							0x18004000 
#define SOC_CONFIG_ADDRESS				0x18005000
#define SECU_FLASH_ADDR					0x18006000
#define USERPAGE 							0x18007000
#define USERPAGE_BACKUP 					0x18008000
#define F_SETTING_ADDRESS       				0x18009000
#define USER_BIN_FILE_OFFSET				0x1800A000
#define USER_BIN_FILE_MQTT_OFFSET		0x1800AB30     //size(1100) test by ZN ----20190610  
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x1800B000

#define SYSTEM_CONFIG_SIZE					(0x8000)

#define SOFTWARE_CODE_ADDRESS			0x1800C000
#define MAX_SOFTWARE_CODE_SIZE			(800*1024)
#define UPGRADE_ADDRESS					0x18100000
#define MAX_UPGRADE_FILE_SIZE				(512*1024)
#define UPGRADE_ADDRESS_END				(UPGRADE_ADDRESS+MAX_UPGRADE_FILE_SIZE)

	#else
#define BOOT_CONFIG							0x180C5000
#define USERPAGE 							0x180C6000
#define USERPAGE_BACKUP 					0x180C7000
#define F_SETTING_ADDRESS       				0x180C8000
#define SECU_FLASH_ADDR					0x180C9000
#define USER_BIN_FILE_OFFSET				0x180CA000
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x180CB000
#define SOC_CONFIG_ADDRESS				0x180CC000
#define SOFTWARE_CODE_ADDRESS			0x18001000
	#endif

#define WEB_ADDRESS						0x18180000
#define WEB_ADDRESS_END					0x181B2000
#define WEB_SCAN_TMPBUF					0x0
#define HFUFLASH_SIZE						(160*1024)
#define HFUFLASH1_SIZE						(0*1024)
#define UFLASH_ADDRESS						0x180D4000
#define UFLASH1_ADDRESS					0x0
#define TEMP_FLASH_ADDRESS				0x181FF000

#elif defined(CONFIG_FLASH_SIZE_4MB)

#define CONFIG_FLASH_SIZE					(1024*1024*4)

	#ifdef HF_OTA_SUPPORT
#define SYSTEM_SECTOR_ADDRESS				0x18000000
#define SYSTEM_SECTOR_SIZE					(0x1000)
#define BOOT_ADDRESS						0x18001000
#define BOOT_SIZE							(0x3000)

#define SOFTWARE_CODE_ADDRESS			0x1800C000
#define MAX_SOFTWARE_CODE_SIZE			(1040*1024)
#define UPGRADE_ADDRESS					(SOFTWARE_CODE_ADDRESS+MAX_SOFTWARE_CODE_SIZE)
#define MAX_UPGRADE_FILE_SIZE				(1008*1024)
#define UPGRADE_ADDRESS_END				(UPGRADE_ADDRESS+MAX_UPGRADE_FILE_SIZE)

#define SYSTEM_CONFIG_SIZE					(0x8000)

#define BOOT_CONFIG							0x18304000 
#define SOC_CONFIG_ADDRESS				0x18305000
#define SECU_FLASH_ADDR					0x18306000
#define USERPAGE 							0x18307000
#define USERPAGE_BACKUP 					0x18308000
#define F_SETTING_ADDRESS       				0x18309000
#define USER_BIN_FILE_OFFSET				0x1830A000
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x1830B000

	#else
#define BOOT_CONFIG							0x180C5000
#define USERPAGE 							0x180C6000
#define USERPAGE_BACKUP 					0x180C7000
#define F_SETTING_ADDRESS       				0x180C8000
#define SECU_FLASH_ADDR					0x180C9000
#define USER_BIN_FILE_OFFSET				0x180CA000
#define USER_BIN_FILE_SIZE					4*1024
#define USER_BIN_FILE_BAK_OFFSET			0x180CB000
#define SOC_CONFIG_ADDRESS				0x180CC000
#define SOFTWARE_CODE_ADDRESS			0x18001000
	#endif

#define WEB_ADDRESS						0x18280000
#define WEB_ADDRESS_END					0x182FFFFF	
#define WEB_SCAN_TMPBUF					0x18300000
#define HFUFLASH_SIZE						(460*1024)
#define HFUFLASH1_SIZE						(240*1024)
#define UFLASH_ADDRESS						0x1820C000
#define UFLASH1_ADDRESS					0x18310000
#define TEMP_FLASH_ADDRESS				0x183FF000

#else

#error must select flash size 1MB or 2MB or 4MB

#endif


#endif

