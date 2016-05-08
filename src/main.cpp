#include "Arduino.h"

String inData;

void setup() {
    Serial.begin(9600);
    Serial.println("Power On");
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 

        // Process message when new line character is recieved
        if (recieved == '\n')
        {
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

            inData = ""; // Clear recieved buffer
        }
    }

}


