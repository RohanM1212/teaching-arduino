# Lesson 6: Servo Motor

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lesson 4 (Potentiometer) — students should be comfortable with analogRead and variables

## Overview

Every lesson so far has been about light. This lesson something actually moves. Students wire a servo motor and use a potentiometer to control the angle it points to.

## Learning goals

Students will learn:
- How to wire a servo motor on a breadboard or TinkerCAD
- What a capacitor does and why the servo needs one (physical track only)
- How to import and use a library in Arduino IDE
- How to use the map() function to convert a potentiometer reading to a servo angle
- How to control servo position with both a potentiometer and a button

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 1 Servo motor
- 1 100 microfarad capacitor (polarized)
- 1 Potentiometer
- 1 Push button
- 1 10kΩ resistor (pull-down for button)
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account
- No capacitor needed in TinkerCAD

### The Physics (Keep it simple)
- A servo rotates to a specific angle and holds there, anywhere from 0 to 180 degrees.
- It has three wires: ground, power, and signal. The signal wire tells it where to go.
- When a servo moves it pulls a lot of current very quickly. A capacitor stores a small charge and releases it when the servo needs it, so the rest of the circuit stays stable. (Physical track only)
- Capacitors are polarized. The negative leg goes to ground. Wire it backwards and it can be damaged.

## Before Lesson

For Physical Setup:
- Test your servo circuit before students arrive, servos can be finicky
- Have the Servo library already imported on the demo computer
- Make sure capacitors are in the kits and check polarity before students wire them
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have the servo circuit built in TinkerCAD ahead of time
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- Don't say anything when you first show the demo. Just turn the knob and let them watch the servo move. The reaction is always better when they don't know what's coming.

## Lesson Plan

### Opening (5 minutes)

Wire up your pre-built circuit and turn the potentiometer. The servo arm sweeps back and forth.

Don't say anything. Just let them watch.

Then ask: "What is different about this compared to everything we have built before?"

They will say it moves. Go from there.

### Review Lesson 4 (5 minutes)

Quick check:
- What does analogRead return?
- Why do we divide by 4 when using analogWrite?
- What is a PWM pin?

If most students remember, move on. If not, do a 2 minute recap before continuing.

### Concept: How a Servo Works (8 minutes)

A servo is not like a regular motor that just spins forever. It rotates to a specific angle and holds there. Anywhere from 0 to 180 degrees depending on the signal you send it.

Inside a servo there is a small motor, a set of gears, and a position sensor. The position sensor tells the servo where it currently is. It keeps adjusting until it reaches the angle you told it to go to.

Servos have three wires:
- Brown or black: ground
- Red: power (5V)
- Orange or yellow or white: signal (connects to an Arduino pin)

For physical track only, the capacitor:

When a servo moves it pulls a lot of current very quickly. This sudden demand can drop the voltage going to the rest of the circuit and cause weird behavior. A capacitor fixes this. It stores a small charge and releases it the moment the servo needs extra power.

Capacitors are polarized, they have a positive and a negative leg. The negative leg is marked with a stripe on the side. Negative leg goes to ground. If you wire it backwards it can be damaged.

### Build the Circuit (20 minutes)

Goal: Potentiometer controls servo angle, button snaps the servo to 180 degrees

Circuit Reference: See `/schematic_examples/lesson_06_servo_circuit.png`

#### Doing it with real parts:

Step 1: Wire the potentiometer
- Left pin to ground rail
- Right pin to 5V rail
- Middle pin to A0

Step 2: Wire the button
- One leg to 5V
- Other leg to Pin 7
- 10kΩ resistor from Pin 7 to ground

Step 3: Wire the capacitor (physical track only)
- Negative leg (striped side) to ground rail
- Positive leg to 5V rail
- Place it close to where the servo connects

Step 4: Wire the servo
- Brown or black wire to ground rail
- Red wire to 5V rail
- Signal wire to Pin 9

Step 5: Plug in USB

Double check the capacitor polarity before powering on. Negative to ground, positive to 5V.

#### Doing it with virtual:

Step 1: Add Arduino, breadboard, potentiometer, push button, servo motor (no capacitor needed)

Step 2: Wire potentiometer
- Left pin to ground
- Right pin to 5V
- Middle pin to A0

Step 3: Wire button
- One terminal to 5V
- Other terminal to Pin 7
- 10kΩ resistor from Pin 7 to ground

Step 4: Wire servo
- Black wire to ground
- Red wire to 5V
- Signal wire to Pin 9

### Write Code Together (20 minutes)

Code Reference: See `/code_examples/lesson_06_servo_motor.ino`

Before typing anything, explain that the servo needs a library. A library is extra code that someone else already wrote that gives us new functions to use. Arduino does not include servo control by default so we have to import it.

Go to Sketch, then Include Library, then search for Servo and add it. Or just type the include line at the top.

Build this line by line:

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

Go through each new thing:

#include Servo.h: imports the servo library and gives us servo functions.

Servo myServo: creates a servo object. Think of it like giving the servo a name so we can talk to it in code.

myServo.attach(9): tells the Arduino our servo is connected to Pin 9.

map(potValue, 0, 1023, 0, 180): takes a number in one range and converts it to a different range. The potentiometer goes from 0 to 1023 and we want an angle from 0 to 180. map() does that conversion cleanly.

myServo.write(angle): tells the servo to move to that angle and hold there.

Upload and test. Turn the potentiometer. Servo should follow it smoothly. Press the button. Servo snaps to 180.

### Expirement Time (15 minutes)

Challenges:

1. Make the button send the servo to 0 degrees instead of 180. Release and it goes back to wherever the potentiometer is pointing.
2. Add a second position. Button press cycles through 0, 90, and 180 one at a time. (Hint: you need a variable to track which position you are on)
3. (Advanced) Make the servo sweep automatically back and forth on its own without the potentiometer. Use a for loop. Then add the button to pause and resume the sweep.

### Show and Tell (5 minutes)

Call on 2-3 students:
- Turn the potentiometer and explain what map() is doing
- Explain what the capacitor does in your own words (physical track)
- Show the button behavior

### Closing (5 minutes)

Review questions:
- What is a library and why do we need one for the servo?
- What does map() do and why is it useful?
- What would happen if you removed the capacitor? (physical track)

Next week preview: Piezo buzzer. The circuit makes sound for the first time.

Cleanup:
- Unplug USB
- Be careful removing the servo, the wires pull out easily
- Return capacitors to the bin carefully, check legs are not bent

## Assessment

During Lesson:
- Does the servo respond smoothly to the potentiometer?
- Can the student explain what map() does?
- Is the capacitor wired correctly? (physical track)

Exit Ticket:
1. What does map(potValue, 0, 1023, 0, 180) do in plain English?
2. Why does the servo need a capacitor but the LED does not? (physical track)
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have a servo responding to the potentiometer and can explain map()

## Common Issues

### Servo twitches constantly and does not hold position
- Loose connection on the signal wire
- Check that signal wire is firmly in Pin 9

### Servo only goes to one extreme and stays there
- Potentiometer outer pins swapped
- Try swapping the ground and 5V connections on the outer pins

### Arduino resets when servo moves (physical track)
- Capacitor missing or wired incorrectly
- Check polarity and connection of the capacitor

### Servo not responding at all
- Library not imported
- Check that myServo.attach() pin number matches the wiring

### TinkerCAD servo jerks instead of sweeping
- delay(15) too short or missing
- Make sure the delay is at the bottom of the loop

## Other Situations

Need support:
- Skip the button and just get the potentiometer controlling the servo first
- Pre-wire the capacitor for physical track students who are nervous about polarity

Advanced:
- Can you make the potentiometer control the speed of an automatic sweep instead of the angle?
- Can you combine the servo with an LED so the brightness changes based on servo angle?

## Teacher Notes

The opening moment matters. Don't explain the servo before you show it moving. Let them see it first.

map() is the concept that sticks from this lesson. It shows up everywhere in robotics. Spend extra time on it if needed.

For physical track: check every capacitor before powering on. A backwards capacitor can pop and it is scary even if it is not dangerous. Walk around and check polarity on every board before they plug in USB.

Timing:
- Opening: 5 min
- Review: 5 min
- Concept: 8 min
- Build: 20 min
- Code: 20 min
- Experiments: 15 min
- Show and tell: 5 min
- Closing: 5 min
- Buffer: 7 min

Prepare:
- Test servo circuit before the session
- Have Servo library imported on the demo computer already

*End of Lesson 6*