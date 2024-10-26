#include "driver/rmt_tx.h"

rmt_channel_handle_t get_led_channel();
rmt_transmit_config_t get_tx_config();
rmt_encoder_handle_t get_encoder();

// will sleep as well
void send_strip(rmt_channel_handle_t channel, rmt_encoder_handle_t encoder, rmt_transmit_config_t tx_config, uint8_t r, uint8_t g, uint8_t b);

