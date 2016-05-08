#include "Arduino.h"

String inData;

int IN1 = 2;//32;//D2
int IN2 = 3;//1;
int IN3 = 4;//2;
int IN4 = 5;//9;

void setup() {
    Serial.begin(9600);
    Serial.println("Power On");
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved;

        // Process message when new line character is received
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
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
            }
            if (inData == "LS\n") {
                Serial.println("Left Motor Stop");
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
            }
            if (inData == "LB\n") {
                Serial.println("Left Motor Backward");
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
            }
            if (inData == "RF\n") {
                Serial.println("Right Motor Forward");
                digitalWrite(IN3, HIGH);
                digitalWrite(IN4, LOW);
            }
            if (inData == "RS\n") {
                Serial.println("Right Motor Stop");
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, LOW);
            }
            if (inData == "RB\n") {
                Serial.println("Right Motor Backward");
                digitalWrite(IN3, LOW);
                digitalWrite(IN4, HIGH);
            }
            inData = ""; // Clear recieved buffer
        }
    }
}

