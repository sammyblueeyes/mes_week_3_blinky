#include <led.h>
#include <io_mapping.h>

enum LEDs {
  LED_BLUE,
  LED_GREEN,
  LED_ORANGE,
  LED_RED,
  LED_MAX,
};


int main(void)
{
  HAL_Init();

  // NOTE (from HAL): After reset, the peripheral clock (used for registers read/write access)
  // is disabled and the application software has to enable this clock before using it.
  LED_GPIO_CLK_ENABLE();

  LED leds[LED_MAX] = {
    LED(LED_GPIO_PORT, BLUE_LED_PIN),
    LED(LED_GPIO_PORT, GREEN_LED_PIN),
    LED(LED_GPIO_PORT, ORANGE_LED_PIN),
    LED(LED_GPIO_PORT, RED_LED_PIN),
  };
  int cur_led = LED_BLUE;

  while (1)
  {
    leds[cur_led].Blink();
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