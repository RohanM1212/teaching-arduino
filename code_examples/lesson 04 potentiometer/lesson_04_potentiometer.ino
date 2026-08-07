/*
  Lesson 4 Potentiometer and Analog Input
  Arduino for Kids Curriculum

  This program uses a potentiometer to control the brightness of an LED.

  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

int potPin = A0;
int ledPin = 9;
int potValue = 0;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  potValue = analogRead(potPin);
  brightness = potValue / 4;
  analogWrite(ledPin, brightness);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  delay(50);

}

//Expirement with it:
// - Turn the knob until the Serial Monitor shows around 512. What brightness does that give you?
// - Add a second LED on Pin 10 that does the opposite. When LED 1 is bright, LED 2 is dim. (Hint: 255 minus brightness)
// - Add an if statement. Below 300 blink fast, above 700 blink slow, in the middle use the knob to dim normally.