#pragma once

#ifdef __cplusplus
 extern "C" {
#endif

#include <io_mapping.h>

void LED_Init()
{
  // NOTE (from HAL): After reset, the peripheral clock (used for registers read/write access)
  // is disabled and the application software has to enable this clock before using it.
  LED_GPIO_CLK_ENABLE();

  // Setup the GPIO:
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = BLUE_LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(BLUE_LED_GPIO_PORT, &GPIO_InitStruct);
}

void LEDBlink() {
    HAL_GPIO_TogglePin(BLUE_LED_GPIO_PORT, BLUE_LED_PIN);
}

#ifdef __cplusplus
 } // extern "C"
#endif