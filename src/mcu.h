/*
 * Copyright (c) 2019 Martin Jäger / Libre Solar
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef MCU_H_
#define MCU_H_

#ifdef CONFIG_SOC_SERIES_STM32F0X
#include "stm32f072xb.h"
#endif

#ifdef CONFIG_SOC_SERIES_STM32L0X
#include "stm32l072xx.h"
#endif

#ifdef CONFIG_SOC_SERIES_STM32G4X
#include "stm32g431xx.h"
#endif

// factory calibration values for internal voltage reference and temperature sensor
// (see MCU datasheet, not Reference Manual)
#if defined(CONFIG_SOC_SERIES_STM32F0X)
    const uint16_t VREFINT_CAL = *((uint16_t *)0x1FFFF7BA); // VREFINT @3.3V/30°C
    #define VREFINT_VALUE 3300 // mV
    const uint16_t TSENSE_CAL1 = *((uint16_t *)0x1FFFF7B8);
    const uint16_t TSENSE_CAL2 = *((uint16_t *)0x1FFFF7C2);
    #define TSENSE_CAL1_VALUE 30.0   // temperature of first calibration point
    #define TSENSE_CAL2_VALUE 110.0  // temperature of second calibration point
#elif defined(CONFIG_SOC_SERIES_STM32L0X)
    const uint16_t VREFINT_CAL = *((uint16_t *)0x1FF80078);   // VREFINT @3.0V/25°C
    #define VREFINT_VALUE 3000 // mV
    const uint16_t TSENSE_CAL1 = *((uint16_t *)0x1FF8007A);
    const uint16_t TSENSE_CAL2 = *((uint16_t *)0x1FF8007E);
    #define TSENSE_CAL1_VALUE 30.0   // temperature of first calibration point
    #define TSENSE_CAL2_VALUE 130.0  // temperature of second calibration point
#elif defined(CONFIG_SOC_SERIES_STM32G4X)
    const uint16_t VREFINT_CAL = *((uint16_t *)0x1FFF75AA);   // VREFINT @3.0V/30°C
    #define VREFINT_VALUE 3000 // mV
    const uint16_t TSENSE_CAL1 = *((uint16_t *)0x1FFF75A8);
    const uint16_t TSENSE_CAL2 = *((uint16_t *)0x1FFF75CA);
    #define TSENSE_CAL1_VALUE 30.0   // temperature of first calibration point
    #define TSENSE_CAL2_VALUE 110.0  // temperature of second calibration point
#elif defined(UNIT_TEST)
    #define VREFINT_CAL (4096 * 1.224 / 3.0)   // VREFINT @3.0V/25°C
    #define VREFINT_VALUE 3000 // mV
    #define TSENSE_CAL1 (4096.0 * (670 - 161) / 3300)     // datasheet: slope 1.61 mV/°C
    #define TSENSE_CAL2 (4096.0 * 670 / 3300)     // datasheet: 670 mV
    #define TSENSE_CAL1_VALUE 30.0   // temperature of first calibration point
    #define TSENSE_CAL2_VALUE 130.0  // temperature of second calibration point
#endif

#endif // MCU_H_
