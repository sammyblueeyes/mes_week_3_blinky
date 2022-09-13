#pragma once

#include <stm32f4xx_hal.h>

#define LED_PIN                                GPIO_PIN_15
#define LED_GPIO_PORT                          GPIOD
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOD_CLK_ENABLE()