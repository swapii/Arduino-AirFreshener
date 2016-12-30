#include <Arduino.h>
#include <LowPower.h>

#define LIGHT_SERSOR_PIN A0
#define LED_PIN 13

#define LIGHT_LEVEL_THRESHOLD 500

unsigned long elapsedTime;

void setup(void) {
    pinMode(LIGHT_SERSOR_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop(void) {

    if (analogRead(LIGHT_SERSOR_PIN) > LIGHT_LEVEL_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
        elapsedTime += 500;
        LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);
    } else {
        digitalWrite(LED_PIN, LOW);
        elapsedTime += 4000;
        LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
    }

}
