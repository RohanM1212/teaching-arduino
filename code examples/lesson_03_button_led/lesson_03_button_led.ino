/*
  Lesson 3 Buttons and Digital Input
  Arduino for Kids Curriculum

  This program turns an LED on when a button is pressed and off when it is released.

  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

int buttonPin = 8;
int ledPin = 13;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}

//Expirement with it:
// - Flip the behavior. Make the LED turn ON when the button is NOT pressed. (Hint: swap HIGH and LOW in the if statement)
// - Add a second LED on Pin 12. Button pressed turns LED 1 on and LED 2 off. Button released flips them.
// - Make the LED blink while the button is held. (Hint: put a delay inside the if statement)