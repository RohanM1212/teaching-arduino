# Lesson 4: Potentiometer and Analog Input

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lesson 3 (Buttons) — students should have a working button circuit

## Overview

Last lesson the button gave us two options. Pressed or not pressed. This lesson we get a number anywhere from 0 to 1023 depending on how far you turn a knob. Students use that to control LED brightness.

## Learning goals

Students will learn:
- How a potentiometer works and what its three pins do
- The difference between analog and digital input
- How to use analogRead to get a value from the potentiometer
- How to use analogWrite to control LED brightness
- How to use the Serial Monitor to see what the Arduino is actually reading

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 1 LED (any color)
- 1 220Ω resistor
- 1 Potentiometer (10k ohm)
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account

### The Physics (Keep it simple)
- A potentiometer is a variable resistor. Turn the knob, change the resistance, change the voltage reaching the middle pin.
- The Arduino reads that voltage and converts it to a number from 0 to 1023.
- analogWrite for LEDs only goes from 0 to 255, so we divide by 4 to fit the range.

## Before Lesson

For Physical Setup:
- Have a working potentiometer circuit ready to demo
- Have Serial Monitor open on your screen before students arrive so they can see the numbers change when you turn the knob
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have the circuit built in TinkerCAD ahead of time
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- Open the Serial Monitor while turning the knob slowly. Let students watch the numbers change in real time before explaining anything.

## Lesson Plan

### Opening (5 minutes)

Turn the knob on your pre-built circuit. The LED gets brighter and dimmer.

Ask: "Last lesson the button only gave us two options. What is different about this?"

Let them figure out that this is gradual. More than two options.

### Review Lesson 3 (5 minutes)

Quick check:
- What does a pull-down resistor do?
- What does digitalRead return?
- What is the difference between INPUT and OUTPUT?

If most students remember, move on. If not, do a 2 minute recap before continuing.

### Concept: Analog vs Digital (10 minutes)

Digital is all or nothing. A light switch is digital. On or off.

Analog is a range. A dimmer switch is analog. Anywhere between fully off and fully on.

The button from last lesson was digital. The potentiometer is analog.

A potentiometer has three pins. The two outer pins connect to power and ground. The middle pin is the wiper. Inside is a strip of resistive material. As you turn the knob, the wiper moves along that strip and changes how much resistance is between the middle pin and each outer pin. More resistance means less voltage at the middle pin.

The Arduino reads that voltage and converts it to a number between 0 and 1023. All the way left is 0. All the way right is 1023. That conversion is done by the ADC, Analog to Digital Converter, built into the Arduino. That is why analog pins are labeled A0 through A5.

One thing to know: analogWrite for LEDs only goes from 0 to 255, not 0 to 1023. So we divide the potentiometer reading by 4. That is the main math of this lesson.

### Build the Circuit (20 minutes)

Goal: Potentiometer controls LED brightness

Circuit Reference: See `/schematic_examples/lesson_04_potentiometer_circuit.png`

#### Doing it with real parts:

Step 1: Wire the LED
- Long leg to Pin 9 (must be a PWM pin, marked with ~ on the board)
- Short leg through 220Ω resistor to ground rail

Step 2: Place the potentiometer on the breadboard
- Left outer pin to ground rail
- Right outer pin to 5V rail
- Middle pin to A0

Step 3: Wire ground rail to GND and 5V rail to 5V on the Arduino

Step 4: Plug in USB

Important: the LED must be on Pin 9, 10, 11, 5, 6, or 3. These are the PWM pins marked with ~. Regular pins can only do fully on or fully off. PWM pins can do in between.

#### Doing it with virtual:

Step 1: Add Arduino, breadboard, LED, 220Ω resistor, potentiometer

Step 2: Wire LED
- Anode to Pin 9
- Cathode through resistor to ground

Step 3: Wire potentiometer
- Left pin to ground
- Right pin to 5V
- Middle pin to A0

Step 4: Click Code, select Text

### Write Code Together (20 minutes)

Code Reference: See `/code_examples/lesson_04_potentiometer.ino`

Build this line by line:

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

Go through each part:

analogRead(potPin): reads the voltage at A0 and gives a number from 0 to 1023.

potValue / 4: shrinks the range from 0-1023 down to 0-255 so we can use it with analogWrite.

analogWrite(ledPin, brightness): unlike digitalWrite which is just HIGH or LOW, analogWrite can be any value from 0 to 255. This is what makes the LED dim instead of just turning fully on or off.

Serial.begin(9600) and Serial.print: open Tools then Serial Monitor after uploading. Turn the knob and watch the numbers change in real time.

Upload and test. Turn the knob. LED should get brighter and dimmer smoothly.

### Expirement Time (15 minutes)

Challenges:

1. Turn the knob until the Serial Monitor shows around 512. What brightness does that give you?
2. Add a second LED on Pin 10 that does the opposite. When LED 1 is bright, LED 2 is dim. (Hint: 255 minus brightness)
3. (Advanced) Add an if statement. If the potentiometer is below 300, blink fast. If it is above 700, blink slow. In the middle, use the potentiometer to control brightness normally.

### Show and Tell (5 minutes)

Call on 2-3 students:
- Turn the knob and explain what is happening inside the potentiometer
- Show the Serial Monitor and explain what the two numbers mean
- Explain why you have to divide by 4

### Closing (5 minutes)

Review questions:
- What is the difference between analogRead and digitalRead?
- Why does the LED need to be on a PWM pin?
- What does dividing by 4 do and why do we need it?

Next week preview: First capstone project. Students use everything from lessons 1 through 4 to build their own circuit from scratch.

Cleanup:
- Unplug USB
- Keep the potentiometer circuit, it gets used in the capstone

## Assessment

During Lesson:
- Does the LED respond smoothly to the potentiometer?
- Can the student explain what analogRead returns?
- Does the student understand why we divide by 4?

Exit Ticket:
1. What is the range of analogRead? What is the range of analogWrite?
2. What does the Serial Monitor show you that you cannot see just by looking at the circuit?
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have smooth LED dimming working and can read the Serial Monitor

## Common Issues

### LED not dimming, just turning on and off
- LED is on a non-PWM pin
- Move the LED wire to Pin 9, 10, or 11

### Serial Monitor shows 0 the whole time
- Middle pin of potentiometer not connected to A0
- Check the wiring on the middle pin specifically

### Numbers jump around a lot
- Loose connection on the potentiometer
- Press down on the potentiometer legs to make sure they are seated in the breadboard

### LED stuck at full brightness or completely off
- Outer pins of potentiometer swapped
- Try swapping the ground and 5V connections on the outer pins

## Other Situations

Need support:
- Have them focus only on getting the LED to dim first, skip Serial Monitor until that works
- Pre-wire the potentiometer and let them focus on the code

Advanced:
- What happens if you use map() instead of dividing by 4? Look up the map() function in the Arduino reference.
- Can you make the potentiometer control the delay in a blinking LED instead of brightness?

## Teacher Notes

The Serial Monitor is the highlight of this lesson. Watching numbers change in real time as you turn a physical knob clicks for most students in a way that just seeing the LED dim does not. Don't skip it.

PWM pins are the most common wiring mistake. Walk around and check that every student has their LED on a PWM pin before they upload code.

Timing:
- Concept: 10 min
- Build: 20 min
- Code: 20 min
- Experiments: 15 min
- Buffer: 15 min for troubleshooting

Prepare:
- Test potentiometer circuit before the session
- Have Serial Monitor open and ready to show

*End of Lesson 4*