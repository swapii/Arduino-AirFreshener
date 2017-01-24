#include <Arduino.h>
#include <LowPower.h>

#define LIGHT_SERSOR_PIN A0
#define MOTOR_PIN 10

#define LIGHT_LEVEL_THRESHOLD 500

bool isLightWasOn = false;

void sleepOneMinute();

void setup(void) {
    pinMode(LIGHT_SERSOR_PIN, INPUT_PULLUP);
    pinMode(MOTOR_PIN, OUTPUT);
}

void loop(void) {

    bool isLightOnNow = analogRead(LIGHT_SERSOR_PIN) > LIGHT_LEVEL_THRESHOLD;

    bool isLightSwitchedOff = !isLightOnNow && isLightWasOn;

    isLightWasOn = isLightOnNow;

    if (isLightSwitchedOff) {

        // Wait 1 second after light off
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);

        digitalWrite(MOTOR_PIN, HIGH);
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
        digitalWrite(MOTOR_PIN, LOW);

        // No need to fresh air right after previous fresh
        sleepOneMinute();
        sleepOneMinute();

    }

    LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF);

}

void sleepOneMinute() {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
}
