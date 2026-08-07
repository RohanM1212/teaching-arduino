/*
  Lesson 2 LED Patterns
  Arduino for Kids Curriculum

  This program makes three LEDs blink in a pattern one at a time.

  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(11, HIGH);
  delay(300);
  digitalWrite(11, LOW);

  digitalWrite(12, HIGH);
  delay(300);
  digitalWrite(12, LOW);

  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);

}

//Expirement with it:
// - Try changing all the 300s to 100. What happens? (They blink faster)
// - Try changing one of them to 1000. What happens? (That LED stays on longer)
// - Try making all three blink together at the same time (Hint, put all three HIGH lines before any of the LOW lines)