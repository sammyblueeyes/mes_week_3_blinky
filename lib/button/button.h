#pragma once

#include <stm32f4xx_hal.h>

class Button {
  private:
    GPIO_TypeDef *m_port;
    uint32_t m_pin;
    bool pressed;
  
  public:
    Button(GPIO_TypeDef *port, uint32_t pin) :
      m_port(port), m_pin(pin)
    {
      // Setup the GPIO:
      GPIO_InitTypeDef GPIO_InitStruct;
      GPIO_InitStruct.Pin = m_pin;
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_PULLUP;
      GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
      HAL_GPIO_Init(m_port, &GPIO_InitStruct);
    }

    bool IsPressed() const {
      // Check state
      GPIO_PinState state = HAL_GPIO_ReadPin(m_port, m_pin);
      return (state == GPIO_PIN_SET);
    }
};
