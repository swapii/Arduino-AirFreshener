#include <Arduino.h>
#include <LowPower.h>

void setup(void) {
}

void loop(void) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}
