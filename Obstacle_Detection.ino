#include <ESP32Servo.h>

// Define pins for the ultrasonic sensor
const int trigPin = 12;
const int echoPin = 14;

// Define pins for the servos
const int servoPin = 2;
const int secondServoPin = 4;

// Create servo objects
Servo myServo;
Servo secondServo;

// Function to calculate the distance from the ultrasonic sensor
long readUltrasonicDistance() {
    // Send a 10us pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the time for the echo to be received
    long duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    long distance = duration * 0.034 / 2;
    return distance;
}

void setup() {
    // Attach the first servo
    myServo.attach(servoPin);

    // Attach the second servo
    secondServo.attach(secondServoPin);

    // Set up the ultrasonic sensor pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Initialize Serial Monitor
    Serial.begin(115200);
}

void loop() {
    // Sweep the servo from 0 to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
        myServo.write(angle);
        delay(15); // Adjust speed of movement

        // Read the distance from the ultrasonic sensor
        long distance = readUltrasonicDistance();

        // Print the distance to the Serial Monitor
        Serial.print("Angle: ");
        Serial.print(angle);
        Serial.print(" - Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // Check if the distance is less than 10 cm
        if (distance < 10) {
            Serial.println("Target detected!");
            delay(2000); // Wait for 2 seconds

            // Move the second servo to the detected angle
            secondServo.write(angle);
            delay(4000); // Wait for 4 seconds

            // Return second servo to home position
            secondServo.write(0); // Adjust as per your home position angle
            delay(500); // Delay for stability
        }
    }

    // Sweep the servo from 180 to 0 degrees
    for (int angle = 180; angle >= 0; angle--) {
        myServo.write(angle);
        delay(15); // Adjust speed of movement

        // Read the distance from the ultrasonic sensor
        long distance = readUltrasonicDistance();

        // Print the distance to the Serial Monitor
        Serial.print("Angle: ");
        Serial.print(angle);
        Serial.print(" - Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // Check if the distance is less than 10 cm
        if (distance < 10) {
            Serial.println("Target detected!");
            delay(4000); // Wait for 2 seconds

            // Move the second servo to the detected angle
            secondServo.write(angle);
            delay(4000); // Wait for 4 seconds

            // Return second servo to home position
            secondServo.write(0); // Adjust as per your home position angle
            delay(500); // Delay for stability
        }
    }
}
