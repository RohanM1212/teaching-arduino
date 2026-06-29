/*
  Lesson 1 Blinking LED
  Arduino for Kids Curriculum
  
  This program makes an LED blink every second.
  
  // Code repository: github.com/RohanM1212/arduino-for-kids
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  
  digitalWrite(13, HIGH);
  delay(1000);
  
  digitalWrite(13, LOW);
  delay(1000);

}

//Expirement with it:
// - Try changing both 1000s to 100. What happens? (It blinks faster)
// - Try changing the first 1000 to 2000. What happens? (It stays on longer than it stays off)
// - Try making it blink 3 times fast, then pause, then repeat (Hint, reapeat the digital write and delay lines)