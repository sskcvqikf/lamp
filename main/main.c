#include "ctl.h"
#include "led.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void app_main(void)
{
  adc_oneshot_unit_handle_t adc_handle = get_adc_handle();
  rmt_channel_handle_t led_channel = get_led_channel();
  rmt_transmit_config_t led_tx_config = get_tx_config();
  rmt_encoder_handle_t led_encoder = get_encoder();
  while(1)
  {
    int val = read_value(adc_handle);
    uint8_t brightness = map(val, 0, 4095, 10, 200);
    send_strip(led_channel, led_encoder, led_tx_config, 0, brightness, brightness);
  }

}

