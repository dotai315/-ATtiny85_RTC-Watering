// Based on https://github.com/JanoVel/attiny_binary_watch/blob/master/code/binaryWatch_firmware.ino

#ifndef _ATTINY_DS1302_H_
#define _ATTINY_DS1302_H_

#include "watering_config.h"
#include <stdint.h>

struct Time {
   uint8_t sc;
   uint8_t hr;
   uint8_t mi;
};

void DS1302_init();
void DS1302_set (Time time);
void DS1302_get (Time *time);

#endif
