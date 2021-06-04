#include <stdint.h>

void Leds_Create(uint16_t * direccion);

void Leds_TurnOn(int led);

void Leds_TurnOff(int led);

void Led_TurnAllOn(void);

void Led_TurnAllOff(void);

uint8_t Led_GetState(int led);
