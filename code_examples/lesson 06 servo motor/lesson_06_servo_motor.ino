/*
  Lesson 6 Servo Motor
  Arduino for Kids Curriculum

  This program uses a potentiometer to control the angle of a servo motor.

  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

#include <Servo.h>

Servo myServo;

int potPin = A0;
int buttonPin = 7;
int potValue = 0;
int angle = 0;
int buttonState = 0;

void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    myServo.write(180);
  } else {
    potValue = analogRead(potPin);
    angle = map(potValue, 0, 1023, 0, 180);
    myServo.write(angle);
  }

  Serial.print("Angle: ");
  Serial.println(angle);

  delay(15);

}

//Expirement with it:
// - Change the button to send the servo to 0 instead of 180. Release and it follows the knob again.
// - Make the servo sweep back and forth automatically using a for loop. (Hint: myServo.write(i) inside the loop)
// - Add an LED that gets brighter as the servo angle increases. (Hint: use the angle variable with analogWrite)