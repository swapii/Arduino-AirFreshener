#include <Arduino.h>

#define LIGHT_SERSOR_PIN A0
#define LED_PIN 13

#define LIGHT_LEVEL_THRESHOLD 500

void setup(void) {
    pinMode(LIGHT_SERSOR_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
}

void loop(void) {

    if (analogRead(LIGHT_SERSOR_PIN) > LIGHT_LEVEL_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(100);

}
