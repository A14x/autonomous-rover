/////////// Credits ///////////
// Example code for HC-SR04 ultrasonic distance sensor with Arduino. No library required. More info: https://www.makerguides.com */

#include <Arduino.h>

// Define Trig and Echo pin:
#define trigPinFront 2
#define echoPinFront 3
#define trigPinBack 4
#define echoPinBack 5
#define leftForwardPin 6
#define leftBackwardPin 7
#define rightForwardPin 8
#define rightBackwardPin 9
#define codeWheelLeft 10
#define codeWheelRight 11


// Define variables:
long duration;
int distance;
int trigPin;
int echoPin;
int8_t safe;

int find_distance(bool direction) {
    
    // if direction bool is 1 find distance in front else find distance behind 
    if (direction){
        trigPin = trigPinFront;
        echoPin = echoPinFront;
    } else {
        trigPin = trigPinBack;
        echoPin = echoPinBack;
    }
    
    // Rest of this function is not authored by me instead see https://www.makerguides.com/

    // Clear the trigPin by setting it LOW:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);

    // Trigger the sensor by setting the trigPin high for 10 microseconds:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
    duration = pulseIn(echoPin, HIGH);
    // Calculate the distance:
    distance = duration * 0.034 / 2;

    // end copied code

    return distance;
}

void forward() {
    digitalWrite(leftBackwardPin, LOW);
    digitalWrite(rightBackwardPin, LOW);
    digitalWrite(leftForwardPin, HIGH);
    digitalWrite(rightForwardPin, HIGH);
}

void backward() {
    digitalWrite(leftForwardPin, LOW);
    digitalWrite(rightForwardPin, LOW);
    digitalWrite(leftBackwardPin, HIGH);
    digitalWrite(rightBackwardPin, HIGH);
}
void stop() {
    digitalWrite(leftBackwardPin, LOW);
    digitalWrite(rightBackwardPin, LOW);
    digitalWrite(leftForwardPin, LOW);
    digitalWrite(rightForwardPin, LOW);
}

// returns 0 if safe 1 if not front 2 if not behind
int8_t is_safe() {
    if (find_distance(1) <= 5){
        return 1;
    } else if (find_distance(0) <= 5){
        return 2;
    } else {
        return 0;
    }
}

float get_speed(bool side /* if 0 left if 1 right */){
    
}

// Execution
void setup() {
    // Define inputs and outputs:
    pinMode(trigPinFront, OUTPUT);
    pinMode(echoPinFront, INPUT);
    pinMode(trigPinBack, OUTPUT);
    pinMode(echoPinBack, INPUT);
    pinMode(leftForwardPin, OUTPUT);
    pinMode(leftBackwardPin, OUTPUT);
    pinMode(rightForwardPin, OUTPUT);
    pinMode(rightBackwardPin, OUTPUT);
    pinMode(codeWheelLeft, INPUT);
    pinMode(codeWheelRight, INPUT);

    backward();
    delay(1000);
}

void loop() {
    forward();
    // safety check
    safe = is_safe();
    if (safe != 0){
        stop();
    }

    delay(50);
}

