/*
  Lesson 7 Switch Statements Loops and the Windshield Wiper
  Arduino for Kids Curriculum

  This program makes a servo wiper with 4 modes controlled by a button.

  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

#include <Servo.h>

Servo myServo;

int potPin = A0;
int buttonPin = 7;
int ledPin = 4;
int servoPin = 9;

int mode = 0;
int servoAngle = 0;
int delayTime = 1000;
int potValue = 0;
bool buttonPressed = false;
unsigned long lastTime = 0;

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Button press cycles to the next mode (0 to 3 then back to 0)
  if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
    buttonPressed = true;
    mode = (mode + 1) % 4;
  }
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = false;
  }

  switch (mode) {

    case 0: // Wiper off
      servoAngle = 0;
      delayTime = 1000;
      break;

    case 1: // Wiper on, constant speed
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      delayTime = 1000;
      break;

    case 2: // Wiper on, speed controlled by potentiometer
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      potValue = analogRead(potPin);
      delayTime = map(potValue, 0, 1023, 100, 2000);
      break;

    case 3: // Pulse mode, wipes 5 times then resets
      digitalWrite(ledPin, HIGH);
      for (int i = 0; i < 5; i++) {
        myServo.write(0);
        delay(1000);
        myServo.write(179);
        delay(1000);
      }
      digitalWrite(ledPin, LOW);
      mode = 0;
      break;

  }

  myServo.write(servoAngle);

  // millis() lets us wait without freezing the program
  // so the button still works during the delay
  lastTime = millis();
  while (millis() - lastTime < delayTime) {
    if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
      buttonPressed = true;
      mode = (mode + 1) % 4;
      break;
    }
    if (digitalRead(buttonPin) == LOW) {
      buttonPressed = false;
    }
  }

}

//Expirement with it:
// - Change case 3 so the wiper pulses 10 times instead of 5. (Hint: change the 5 in the for loop)
// - Add a fifth mode that makes the LED blink while the servo sweeps. (Hint: add case 4 and update the % to 5)
// - In case 2, make the potentiometer control the angle instead of the speed. (Hint: map it to servoAngle not delayTime)