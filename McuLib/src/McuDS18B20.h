/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuDS18B20.h
**     CDE edition : Community
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : DS18B20
**     Version     : Component 01.020, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-08-14, 06:24, # CodeGen: 679
**     Abstract    :
**
This is a component for the Maxim DS18B20 1-Wire temperature sensor.
**     Settings    :
**          Component Name                                 : McuDS18B20
**          Temperature Reading                            : Auto
**          Connection mode                                : One slave
**          One Wire                                       : McuOneWire
**          SDK                                            : McuLib
**          Shell                                          : Enabled
**            Shell                                        : McuShell
**            Utility                                      : McuUtility
**     Contents    :
**         ReadRom                 - uint8_t McuDS18B20_ReadRom(uint8_t sensor_index);
**         GetRomCode              - uint8_t McuDS18B20_GetRomCode(uint8_t sensor_index, uint8_t **romCodePtr);
**         isBusy                  - bool McuDS18B20_isBusy(void);
**         StartConversion         - uint8_t McuDS18B20_StartConversion(uint8_t sensor_index);
**         ReadTemperature         - uint8_t McuDS18B20_ReadTemperature(uint8_t sensor_index);
**         GetTemperatureRaw       - uint8_t McuDS18B20_GetTemperatureRaw(uint16_t sensor_index, uint32_t *raw);
**         GetTemperatureFloat     - uint8_t McuDS18B20_GetTemperatureFloat(uint8_t sensor_index, float...
**         ReadResolution          - uint8_t McuDS18B20_ReadResolution(uint8_t sensor_index);
**         SetResolution           - uint8_t McuDS18B20_SetResolution(uint8_t sensor_index, DS18B20_ResolutionBits...
**         SearchAndAssignROMCodes - uint8_t McuDS18B20_SearchAndAssignROMCodes(void);
**         ParseCommand            - uint8_t McuDS18B20_ParseCommand(const unsigned char* cmd, bool *handled,...
**         Init                    - void McuDS18B20_Init(void);
**         Deinit                  - void McuDS18B20_Deinit(void);
**
** * Copyright (c) Original implementation: Omar Isa� Pinales Ayala, 2014, all rights reserved.
**  * Updated and maintained by Erich Styger, 2014-2020
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuDS18B20.h
** @version 01.00
** @brief
**
This is a component for the Maxim DS18B20 1-Wire temperature sensor.
*/         
/*!
**  @addtogroup McuDS18B20_module McuDS18B20 module documentation
**  @{
*/         

#ifndef __McuDS18B20_H
#define __McuDS18B20_H

/* MODULE McuDS18B20. */
#include "McuLib.h" /* SDK and API used */
#include "McuDS18B20config.h" /* configuration */
#include "McuShell.h" /* Shell */

#ifdef __cplusplus
extern "C" {
#endif


/* sensor resolution */
typedef enum {
  DS18B20_RESOLUTION_BITS_9  = 0b00, /* conversion time: 93.75 ms */
  DS18B20_RESOLUTION_BITS_10 = 0b01, /* conversion time: 187.5 ms */
  DS18B20_RESOLUTION_BITS_11 = 0b10, /* conversion time: 375 ms */
  DS18B20_RESOLUTION_BITS_12 = 0b11  /* conversion time: 750 ms */
} DS18B20_ResolutionBits;

#define DS18B20_FAMILY_CODE    0x28  /* 8-bit family code for DS128B20 */
#define DS18B20_ROM_CODE_SIZE  8     /* 8 byte ROM code (family ID, 6 bytes for ID plus 1 byte CRC */

#define McuDS18B20_PARSE_COMMAND_ENABLED  McuDS18B20_CONFIG_PARSE_COMMAND_ENABLED
  /*!< set to 1 if method ParseCommand() is present, 0 otherwise */
uint8_t McuDS18B20_StartConversion(uint8_t sensor_index);
/*
** ===================================================================
**     Method      :  StartConversion (component DS18B20)
**
**     Description :
**         Starts the conversion of temperature in the sensor.
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t McuDS18B20_SetResolution(uint8_t sensor_index, DS18B20_ResolutionBits resolution);
/*
** ===================================================================
**     Method      :  SetResolution (component DS18B20)
**
**     Description :
**         Sets the resolution
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Index of the sensor to
**                           set the resolution.
**         config_bits     - Two bits resolution config
**                           value: 
**                           [0b00] - 9 bits.
**                           [0b01] - 10 bits.
**                           [0b10] - 11 bits.
**                           [0b11] - 12 bits.
**     Returns     :
**         ---             - error code
** ===================================================================
*/


uint8_t McuDS18B20_ReadTemperature(uint8_t sensor_index);
/*
** ===================================================================
**     Method      :  ReadTemperature (component DS18B20)
**
**     Description :
**         Read the temperature value from the sensor and stores it in
**         memory
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t McuDS18B20_GetTemperatureRaw(uint16_t sensor_index, uint32_t *raw);
/*
** ===================================================================
**     Method      :  GetTemperature (component DS18B20)
**
**     Description :
**         Gets the temperature from memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * sensor_index    - Index of the sensor to
**                           get the temperature value.
**     Returns     :
**         ---             - 
** ===================================================================
*/

bool McuDS18B20_isBusy(void);
/*
** ===================================================================
**     Method      :  isBusy (component DS18B20)
**
**     Description :
**         Returns TRUE if there are a operation in progress.
**     Parameters  : None
**     Returns     :
**         ---             - Returns TRUE if the device is busy, and
**                           FALSE if its ready to operate.
** ===================================================================
*/

uint8_t McuDS18B20_GetRomCode(uint8_t sensor_index, uint8_t **romCodePtr);
/*
** ===================================================================
**     Method      :  GetRomCode (component DS18B20)
**
**     Description :
**         Gets the rom code from the memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**       * romCodePtr      - Pointer to a pointer for the
**                           return value
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t McuDS18B20_ReadRom(uint8_t sensor_index);
/*
** ===================================================================
**     Method      :  ReadRom (component DS18B20)
**
**     Description :
**         Starts to read the rom code and saves it in memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**     Returns     :
**         ---             - error code
** ===================================================================
*/

void McuDS18B20_Init(void);
/*
** ===================================================================
**     Method      :  Init (component DS18B20)
**
**     Description :
**         Initializes the device.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuDS18B20_GetTemperatureFloat(uint8_t sensor_index, float *temperature);
/*
** ===================================================================
**     Method      :  GetTemperatureFloat (component DS18B20)
**
**     Description :
**         Returns the temperature from memory in floating point format.
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**       * temperature     - Pointer to where to store
**                           the value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t McuDS18B20_ParseCommand(const unsigned char* cmd, bool *handled, const McuShell_StdIOType *io);
/*
** ===================================================================
**     Method      :  ParseCommand (component DS18B20)
**
**     Description :
**         Shell Command Line parser. Method is only available if Shell
**         is enabled in the component properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**         io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void McuDS18B20_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component DS18B20)
**
**     Description :
**         Driver deinitialization routine
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuDS18B20_ReadResolution(uint8_t sensor_index);
/*
** ===================================================================
**     Method      :  ReadResolution (component DS18B20)
**
**     Description :
**         Read the sensor resolution sensor and stores it in memory
**     Parameters  :
**         NAME            - DESCRIPTION
**         sensor_index    - Sensor index, use zero
**                           if only using one sensor
**     Returns     :
**         ---             - error code
** ===================================================================
*/

uint8_t McuDS18B20_SearchAndAssignROMCodes(void);
/*
** ===================================================================
**     Method      :  SearchAndAssignROMCodes (component DS18B20)
**
**     Description :
**         Scans the devices on the bus and assigns the ROM codes to
**         the list of available sensors
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END McuDS18B20. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __McuDS18B20_H */
/*!
** @}
*/
