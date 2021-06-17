#include "unity.h"
#include "leds.h"


static uint16_t ledsVirtuales;

void setUp(void)
{
    Leds_Create(&ledsVirtuales);
}

void tearDown(void)
{
}

void test_LedsOffAfterCreate(void)
{
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOnLedOne(void)
{
    Leds_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

void test_TurnOffLedOne(void)
{
    Leds_TurnOn(1);
    Leds_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOnMultipleLeds(void)
{
    Leds_TurnOn(8);
    Leds_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(((1<<8)|(1<<7)), ledsVirtuales);
}

void test_TurnAllOn(void)
{
    Led_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

void test_TurnOffAnyLed(void)
{
    Led_TurnAllOn();
    Leds_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, ledsVirtuales);
}

void test_TurnAllOff(void)
{
	Led_TurnAllOn();
	Led_TurnAllOff();
	TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_TurnOffMultipleLeds(void)
{
    Led_TurnAllOn();
    Leds_TurnOff(8);
    Leds_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16((uint16_t) ~((1<<7)|(1<<8)), ledsVirtuales);
}

void test_GetStateOff(void)
{
    Led_TurnAllOn();
    Leds_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(1, (uint16_t) Led_CheckIfOff(1));
}

void test_GetStateOn(void)
{
	Leds_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1,  (uint16_t) Led_CheckIfOn(1));

}

void test_LedMemoryIsNotReadable(void)
{
    ledsVirtuales = 0xFFFF;
    Leds_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080, ledsVirtuales);
}

void test_LedOutOfLimits(void)
{

    Led_TurnAllOn();
    Leds_TurnOff(17);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);

    TEST_ASSERT_EQUAL_HEX16(0, (uint16_t) Led_CheckIfOff(17));

    Led_TurnAllOff();
    Leds_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);

    TEST_ASSERT_EQUAL_HEX16(0, (uint16_t) Led_CheckIfOff(17));
}
