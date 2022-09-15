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

// stm32cube overrides are C functions
extern "C" {

  void SysTick_Handler(void)
  {
    HAL_IncTick();
  }

} // extern "C"