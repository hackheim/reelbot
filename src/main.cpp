#include "Arduino.h"

String inData;

void setup() {
    Serial.begin(9600);
    Serial.println("Power On");
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(D9, OUTPUT);
    pinMode(D10, OUTPUT);
    pinMode(D11, OUTPUT);
    pinMode(D12, OUTPUT);
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
//LEDS 9 10 11 12
           if (inData == "LF\n") {
                Serial.println("Left Motor Forward");
                digitalWrite(D9, HIGH);
                digitalWrite(D10, LOW);
            }
            if (inData == "LS\n") {
                Serial.println("Left Motor Stop");
                digitalWrite(D9, LOW);
                digitalWrite(D10, LOW);
            }
            if (inData == "LB\n") {
                Serial.println("Left Motor Backward");
                digitalWrite(D9, LOW);
                digitalWrite(D10, HIGH);
            }
            if (inData == "RF\n") {
                Serial.println("Right Motor Forward");
                digitalWrite(D11, HIGH);
                digitalWrite(D12, LOW);
            }
            if (inData == "RS\n") {
                Serial.println("Right Motor Stop");
                digitalWrite(D11, LOW);
                digitalWrite(D12, LOW);
            }
            if (inData == "RB\n") {
                Serial.println("Right Motor Backward");
                digitalWrite(D11, LOW);
                digitalWrite(D12, HIGH);
            }
            inData = ""; // Clear recieved buffer
        }
    }
}


