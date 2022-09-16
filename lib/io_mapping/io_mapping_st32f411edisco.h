#pragma once

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include <stm32f4xx_hal.h>

#define BLUE_LED_PIN                GPIO_PIN_15
#define BLUE_LED_GPIO_PORT          GPIOD
#define LED_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOD_CLK_ENABLE()

#define BUTTON_PIN                  GPIO_PIN_0
#define BUTTON_GPIO_PORT            GPIOA

#ifdef __cplusplus
 } // extern "C"
#endif