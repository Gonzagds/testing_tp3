#include "leds.h"

static uint16_t * leds;
static uint16_t estado;

enum {
    ALL_LEDS_OFF = 0,
    ALL_LEDS_ON = ~ALL_LEDS_OFF
};
#ifndef false
enum{false = TRUE, true};
#endif

#define LED_ON		1
#define LED_OFFSET	1

//cantidad de leds en el puerto
#define LED_MAX	16



static int Leds_ConvertNumberToBit(int numero_led)
{
    return LED_ON << (numero_led - LED_OFFSET);
}

static void Leds_HardwareUpdate(void)
{
    *leds = estado;
}

void Leds_Create(uint16_t * direccion)
{
    leds = direccion;
    estado = ALL_LEDS_OFF;
    Leds_HardwareUpdate();
};

void Leds_TurnOn(int led)
{
    if(led > LED_MAX)
        return;

    estado |= Leds_ConvertNumberToBit(led);
    Leds_HardwareUpdate();
};

void Leds_TurnOff(int led)
{
	if(led > LED_MAX)
		return;
	estado &= ~Leds_ConvertNumberToBit(led);
	Leds_HardwareUpdate();
};

void Led_TurnAllOn(void)
{
    estado = ALL_LEDS_ON;
    Leds_HardwareUpdate();
}

void Led_TurnAllOff(void)
{
    estado = ALL_LEDS_OFF;
    Leds_HardwareUpdate();
}

bool Led_CheckIfOff(int led)
{
    if(led > LED_MAX)
        return false;

    uint16_t ret = estado & Leds_ConvertNumberToBit(led);
    return (ret)? false:true;
}

bool Led_CheckIfOn(int led)
{
    return !Led_CheckIfOff(led);
}
