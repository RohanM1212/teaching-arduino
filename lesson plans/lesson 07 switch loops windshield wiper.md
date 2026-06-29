# Lesson 7: Switch Statements, Loops, and the Windshield Wiper

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lesson 6 (Servo Motor) — students should have a working servo circuit

## Overview

No new components this lesson. This one is all about coding. Students learn switch statements, for loops, and while loops by building a windshield wiper circuit that has four different modes.

## Learning goals

Students will learn:
- What a switch statement is and when to use it instead of if statements
- How a for loop works and when to use it
- How a while loop works and when to use it
- How to use millis() to check time without stopping the whole program
- Why usability matters when designing anything

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 1 Servo motor
- 1 100 microfarad capacitor (polarized)
- 1 Potentiometer
- 1 Push button
- 1 10kΩ resistor (pull-down for button)
- 1 LED
- 1 220Ω resistor (for LED)
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account
- No capacitor needed in TinkerCAD

### The Physics (Keep it simple)
- No new components today. Everything here is from lessons 5 and 6.
- The capacitor is still needed to protect the circuit when the servo moves. (Physical track only)

## Before Lesson

For Physical Setup:
- Have a working windshield wiper circuit pre-built to show all four modes
- Test that the button changes modes correctly before students arrive
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have the windshield wiper circuit built in TinkerCAD ahead of time
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- When going through the switch statement, ask students to think of a real life example before giving them the restaurant one. See what they come up with.

## Lesson Plan

### Opening (5 minutes)

Show the pre-built windshield wiper circuit. Press the button once and the wiper starts moving at a constant speed. Press it again and the speed changes with the potentiometer. Press it again and the LED turns on and it pulses 5 times then stops.

Ask: "How do you think the code knows which mode to be in?"

Let them guess. Then tell them they are about to learn exactly how.

### Review Lesson 6 (5 minutes)

Quick check:
- What does myServo.write() do?
- What does map() do?
- What are the three wires on a servo?

If most students remember, move on. If not, do a 2 minute recap before continuing.

### Concept: Switch Statements (10 minutes)

A switch statement has a certain number of cases or modes. Each case does something different. When the mode changes, the behavior changes.

Think of it like a menu at a restaurant. If you pick the first item, that is case 0. The kitchen does one thing. If you pick the second item, that is case 1. The kitchen does something completely different. That is how a switch statement works.

You could do this with a bunch of if else statements, but switch is cleaner and easier to manage. Imagine having 5 if else statements versus 5 switch cases. The brackets alone in the if else version would be a mess.

Here is the basic structure:

switch (mode) {
  case 0:
    // do something
    break;
  case 1:
    // do something different
    break;
}

The break at the end of each case tells the Arduino to stop and not fall through to the next one.

### Concept: For and While Loops (10 minutes)

For loop:

A for loop runs a specific number of times. You give it a starting value, a condition for when to stop, and how much to increment each time.

for (int i = 0; i < 5; i++) {
  // this runs 5 times
}

Starts at 0, runs while i is less than 5, adds 1 each time. Use a for loop when you know exactly how many times you want something to repeat.

While loop:

A while loop runs as long as a condition is true.

while (condition == true) {
  // keeps running until condition becomes false
}

Use a while loop when you do not know ahead of time how many times it will run. For example, keep blinking until the button is pressed.

The difference:
- For loop: use it when you know the exact number of repeats
- While loop: use it when you do not know, and something else will stop it

One thing to always watch for with both: make sure the condition will eventually be false. If it never becomes false, the loop runs forever and the program freezes. That is an infinite loop.

### Build the Circuit (15 minutes)

Goal: Windshield wiper with 4 modes controlled by a button

Circuit Reference: See `/schematic_examples/lesson_07_windshield_wiper_circuit.png`

#### Doing it with real parts:

Step 1: Wire the capacitor
- Negative leg (striped side) to ground rail
- Positive leg to 5V rail

Step 2: Wire the servo
- Brown or black wire to ground rail
- Red wire to 5V rail
- Signal wire to Pin 9

Step 3: Wire the potentiometer
- Left pin to ground rail
- Right pin to 5V rail
- Middle pin to A0

Step 4: Wire the button
- One leg to 5V
- Other leg to Pin 7
- 10kΩ resistor from Pin 7 to ground

Step 5: Wire the LED
- Long leg to Pin 4
- Short leg through 220Ω resistor to ground

Step 6: Plug in USB

#### Doing it with virtual:

Step 1: Add Arduino, breadboard, servo, potentiometer, button, LED, 220Ω resistor, 10kΩ resistor (no capacitor)

Step 2: Wire servo
- Signal wire to Pin 9, power to 5V, ground to ground

Step 3: Wire potentiometer
- Left pin to ground, right pin to 5V, middle pin to A0

Step 4: Wire button
- One terminal to 5V, other to Pin 7, 10kΩ resistor from Pin 7 to ground

Step 5: Wire LED
- Anode through 220Ω resistor to Pin 4, cathode to ground

### Write Code Together (25 minutes)

Code Reference: See `/code_examples/lesson_07_windshield_wiper.ino`

Most complex code we have done so far. Build it slowly.

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
  if (digitalRead(buttonPin) == HIGH && !buttonPressed) {
    buttonPressed = true;
    mode = (mode + 1) % 4;
  }
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = false;
  }

  switch (mode) {
    case 0:
      servoAngle = 0;
      delayTime = 1000;
      break;

    case 1:
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      delayTime = 1000;
      break;

    case 2:
      if (servoAngle == 0) servoAngle = 179;
      else servoAngle = 0;
      potValue = analogRead(potPin);
      delayTime = map(potValue, 0, 1023, 100, 2000);
      break;

    case 3:
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

Go through the key parts:

mode = (mode + 1) % 4: this cycles the mode from 0 to 3 and wraps back to 0. The % is the modulus operator. It gives you the remainder after dividing. 4 % 4 is 0, so after mode 3 it goes back to mode 0.

switch (mode): checks the current mode and runs whichever case matches.

case 3 uses a for loop because we know exactly how many times we want the wiper to pulse. 5 times. After the loop finishes, mode resets to 0 and the LED turns off.

The while loop at the bottom: instead of using delay(), which would stop the whole program and make the button unresponsive, we use millis() to track time while still checking the button. This is the fix to the button problem you might have noticed in earlier lessons.

Upload and test. Press the button to cycle through the modes.

### Expirement Time (10 minutes)

Challenges:

1. Change case 3 so the wiper pulses 10 times instead of 5.
2. Add a fifth mode that makes the LED blink while the servo sweeps back and forth.
3. (Advanced) Change the potentiometer in case 2 so it controls the sweep angle instead of the speed. (Hint: map the potentiometer to the servo angle, not the delay)

### Show and Tell (5 minutes)

Call on 2-3 students:
- Show all four modes working
- Explain what the for loop in case 3 does in plain English
- Explain why we use millis() instead of delay()

### Closing (5 minutes)

Review questions:
- What is the difference between a for loop and a while loop?
- What happens if your loop condition never becomes false?
- Why does the button feel more responsive in this code than in earlier lessons?

Cleanup:
- Unplug USB
- Keep the circuit if possible, some components carry over

## Assessment

During Lesson:
- Can the student explain when to use a for loop versus a while loop?
- Do all four modes work correctly?
- Can they explain what mode = (mode + 1) % 4 does?

Exit Ticket:
1. Write a for loop that runs exactly 3 times
2. What is an infinite loop and how do you avoid one?
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have all four modes working and can explain the difference between for and while loops

## Common Issues

### Button changes multiple modes at once
- Button debouncing issue
- The buttonPressed variable in the code handles this, make sure students copied it correctly

### Mode 3 gets stuck and never returns to mode 0
- Check that mode = 0 is inside case 3 after the for loop
- Make sure the break is not cutting out early

### Servo not moving in any mode
- Check myServo.attach() is in setup
- Check signal wire is on Pin 9

### While loop freezes the program
- Condition never becomes false
- Check that buttonPressed is being reset to false when button is released

## Other Situations

Need support:
- Get modes 0 and 1 working first before touching modes 2 and 3
- Walk through the switch statement one case at a time

Advanced:
- Can you add a display that shows the current mode number?
- Can you make the sweep speed in case 2 increase as you turn the knob one way and decrease as you turn it the other?

## Teacher Notes

The millis() explanation is the most important concept in this lesson. Students will have noticed in earlier lessons that delay() makes the button unresponsive. This lesson explains why and shows the fix. Make sure that lands.

Switch statements are cleaner than if else chains but students need to see both side by side to appreciate it. If you have time, write the same logic with if else statements first and then show the switch version. The difference is obvious.

The for loop in case 3 is a perfect example of when to use a for loop over a while loop. You know exactly how many times you want the wiper to pulse. Point that out explicitly.

Timing:
- Opening: 5 min
- Review: 5 min
- Switch concept: 10 min
- For and while concept: 10 min
- Build: 15 min
- Code: 25 min
- Experiments: 10 min
- Show and tell: 5 min
- Closing: 5 min
- Buffer: 5 min

Prepare:
- Test all four modes before the session
- Have the circuit already wired to demo quickly

*End of Lesson 7*