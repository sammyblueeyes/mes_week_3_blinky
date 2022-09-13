#define TARGET_ST32F411EDOSCO

#include <led.h>

int main(void)
{
  HAL_Init();
  LED_Init();

  while (1)
  {
    LEDBlink();
    HAL_Delay(1000);
  }
}



void SysTick_Handler(void)
{
  HAL_IncTick();
}