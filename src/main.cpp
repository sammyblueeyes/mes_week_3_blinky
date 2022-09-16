#include <led.h>
#include <button.h>
#include <io_mapping.h>
#include <memory>

enum LEDs {
  LED_BLUE,
  LED_GREEN,
  LED_ORANGE,
  LED_RED,
  LED_MAX,
};

struct ProgramState {
    std::unique_ptr<LED> leds[LED_MAX];
    std::unique_ptr<Button> button;
};


const uint32_t BLINK_INTERVAL_MS = 1000;
const uint32_t LOOP_INTERVAL_MS = 5; 


int main(void)
{
  HAL_Init();

  // NOTE (from HAL): After reset, the peripheral clock (used for registers read/write access)
  // is disabled and the application software has to enable this clock before using it.
  LED_GPIO_CLK_ENABLE();

  ProgramState g_state;
  g_state.leds[LED_BLUE] = std::make_unique<LED>(LED_GPIO_PORT, BLUE_LED_PIN);
  g_state.leds[LED_GREEN] = std::make_unique<LED>(LED_GPIO_PORT, GREEN_LED_PIN);
  g_state.leds[LED_ORANGE] = std::make_unique<LED>(LED_GPIO_PORT, ORANGE_LED_PIN);
  g_state.leds[LED_RED] = std::make_unique<LED>(LED_GPIO_PORT, RED_LED_PIN);
  g_state.button = std::make_unique<Button>(BUTTON_GPIO_PORT, BUTTON_PIN);

  int cur_led = LED_BLUE;
  uint32_t blink_elapsed = 0;

  while (1)
  {
    if (g_state.button->IsPressed()) {
      g_state.leds[cur_led]->TurnOff();
      blink_elapsed = BLINK_INTERVAL_MS;
    } else {
      blink_elapsed += LOOP_INTERVAL_MS;
      if (blink_elapsed >= BLINK_INTERVAL_MS) {
        blink_elapsed = 0;
        g_state.leds[cur_led]->Blink();
      }
    }
    HAL_Delay(LOOP_INTERVAL_MS);
  }
}

// stm32cube overrides are C functions
extern "C" {

  void SysTick_Handler(void)
  {
    HAL_IncTick();
  }

} // extern "C"