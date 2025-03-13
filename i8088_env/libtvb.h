#include <stdint.h>

void bootloader();

void out_byte(int16_t channel, char message);

char in_byte(int16_t channel);

volatile int init();
