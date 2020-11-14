// Include the library for the L298N motor controller
#include <L298N.h>

// Pin definition for the Left motor
const unsigned int IN1_A = 2;
const unsigned int IN2_A = 3;
const unsigned int EN_A = 9;

// Pin definition for the Right motor
const unsigned int IN1_B = 4;
const unsigned int IN2_B = 5;
const unsigned int EN_B = 10;

// Specify the "speedness" 0 = 0%, 255 = 100%
// We set 150 by default (about 58%) to stay safe
int speedness = 150;

// Define the motors
L298N motorLeft(EN_A, IN1_A, IN2_A);
L298N motorRight(EN_B, IN1_B, IN2_B);

// the setup function runs once when you press reset or power the board
void setup() {
  motorLeft.setSpeed(speedness);
  motorRight.setSpeed(speedness);
}

// the loop function runs over and over again forever
void loop() {
  forwards();  // Move forwards
  delay(1000); // wait for a second
  stop();      // Stop the motors
  delay(1000); // wait for a second
  left();      // Turn left
  delay(1000); // wait for a second
  stop();      // Stop the motors
  delay(1000); // wait for a second
  backwards(); // Move backwards
  delay(1000); // wait for a second
  stop();      // Stop the motors
  delay(1000); // wait for a second
  right();     // Turn Right
  delay(1000); // wait for a second
  stop();      // Stop the motors
  delay(1000); // wait for a second
}

// Move the robot forwards.
// note one of the motors is "backwards" since it's
// mounted backwards on the robot
void forwards() {
  motorLeft.forward();
  motorRight.backward();
}

// Move the robot backwards.
void backwards() {
  motorLeft.backward();
  motorRight.forward();
}

// Turn the robot left
void left() {
  motorLeft.backward();
  motorRight.backward();
}

// Turn the robot right
void right() {
  motorLeft.forward();
  motorRight.forward();
}

// Stop the robot and all motors
void stop() {
  motorLeft.stop();
  motorRight.stop();
}
