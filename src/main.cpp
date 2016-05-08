#include "Arduino.h"

String inData;
const int D7 = 10;
const int D8 = 11;
const int D9 = 12;
const int D10 = 13;

void setup() {
    Serial.begin(9600);
    Serial.println("Power On");
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT);
    pinMode(D9, OUTPUT);
    pinMode(D10, OUTPUT);
}

void loop()
{
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved;

        // Process message when new line character is recieved
        if (recieved == '\n'){
            Serial.println("Arduino Received: ");
            Serial.println(inData);
            if (inData == "m1 on\n") {
                Serial.println("Motor 1 -> Online");
                digitalWrite(LED_BUILTIN, HIGH);
            }
            if (inData == "m1 off\n") {
                Serial.println("Motor 1 -> Offline");
                digitalWrite(LED_BUILTIN, LOW);
            }
//LEDS 7 8 9 10
           if (inData == "LF\n") {
                Serial.println("Left Motor Forward");
                digitalWrite(D7, HIGH);
                digitalWrite(D8, LOW);
            }
            if (inData == "LS\n") {
                Serial.println("Left Motor Stop");
                digitalWrite(D7, LOW);
                digitalWrite(D8, LOW);
            }
            if (inData == "LB\n") {
                Serial.println("Left Motor Backward");
                digitalWrite(D7, LOW);
                digitalWrite(D8, HIGH);
            }
            if (inData == "RF\n") {
                Serial.println("Right Motor Forward");
                digitalWrite(D9, HIGH);
                digitalWrite(D10, LOW);
            }
            if (inData == "RS\n") {
                Serial.println("Right Motor Stop");
                digitalWrite(D9, LOW);
                digitalWrite(D10, LOW);
            }
            if (inData == "RB\n") {
                Serial.println("Right Motor Backward");
                digitalWrite(D9, LOW);
                digitalWrite(D10, HIGH);
            }
            inData = ""; // Clear recieved buffer
        }
    }
}


