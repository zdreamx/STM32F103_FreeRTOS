#ifndef _LED_H
#define _LED_H

#include "stdint.h"

void LED_Init(void);

//点亮LED等
//led=1点亮  led=0不亮
void LED_Light(uint16_t led);

#endif
