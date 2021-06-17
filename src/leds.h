#include <stdint.h>
#include <stdbool.h>

void Leds_Create(uint16_t * direccion);

void Leds_TurnOn(int led);

void Leds_TurnOff(int led);

void Led_TurnAllOn(void);

void Led_TurnAllOff(void);

bool Led_CheckIfOff(int led);

bool Led_CheckIfOn(int led);
