# Lesson 3: Buttons and Digital Input

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lesson 2 (LED Patterns) — students should have a working parallel LED circuit

## Overview

Last lesson the LEDs just did whatever the code told them to. This lesson the circuit actually reacts to something. Students add a button and write code that responds to it.

## Learning goals

Students will learn:
- How to wire a push button on a breadboard or TinkerCAD
- What a pull-down resistor does and why it is needed
- How to use digitalRead to check button state in code
- How to write an if statement that controls an LED based on button input

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 1 LED (any color)
- 1 220Ω resistor (for LED)
- 1 Push button
- 1 10kΩ resistor (pull-down, for button)
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account

### The Physics (Keep it simple)
- A button is just a gap in a circuit. Press it and the gap closes, electricity flows. Release it and the gap opens, electricity stops.
- Without a pull-down resistor, the pin is floating and picks up random noise from the environment. The LED might flicker or turn on by itself.
- The 10k pull-down resistor gives the pin a clear path to ground when the button is not pressed, so it always reads LOW until you actually press it.

## Before Lesson

For Physical Setup:
- Have a working button circuit pre-built to show
- Have a second circuit ready without the pull-down resistor to show what floating looks like
- Test that the button registers correctly before students arrive
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have a working button circuit built in TinkerCAD ahead of time
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- Show the circuit without a pull-down resistor first. Let them see the random flickering before explaining why it happens.

## Lesson Plan

### Opening (5 minutes)

Show the pre-built circuit. Press the button. LED turns on. Release it. LED turns off.

Ask: "What do you think is happening inside the button when you press it?"

Let them guess. Most will say something about electricity getting through, which is right. Go from there.

### Review Lesson 2 (5 minutes)

Quick check:
- What is the difference between series and parallel?
- What does pinMode do?
- What does digitalWrite(13, HIGH) do?

If most students remember, move on. If not, do a 2 minute recap before continuing.

### Concept: How a Button Works (8 minutes)

A button is the simplest input component. When you press it, you physically close a gap in the circuit. Electricity can flow through. When you release it, the gap opens again and electricity stops.

Draw this or show it on the projector:

NOT PRESSED:   Pin 8 ---[gap]--- 5V      (no connection, no signal)
PRESSED:       Pin 8 ----------- 5V      (connected, signal goes HIGH)

The Arduino reads this as LOW when the button is not pressed and HIGH when it is pressed.

Now here is the problem. Without a pull-down resistor, the pin is floating. It is not connected to anything when the button is released. A floating pin picks up random electrical noise from the environment and gives unpredictable readings. The LED might flicker or turn on randomly even when you are not pressing anything.

Show the circuit without a pull-down resistor if you have one ready. Let them see the random behavior. Then show what happens when you add the resistor. The difference is obvious.

The fix is a 10k pull-down resistor connecting the pin to ground. When the button is not pressed, the pin has a clear path to ground and reads LOW. When the button is pressed, 5V overpowers the resistor and the pin reads HIGH. The signal is now predictable.

### Build the Circuit (20 minutes)

Goal: One LED controlled by one button

Circuit Reference: See `/schematic_examples/lesson_03_button_circuit.png`

#### Doing it with real parts:

Step 1: Place the LED on the breadboard
- Long leg Row 5 left side
- Short leg Row 5 right side
- 220Ω resistor from short leg to ground rail
- Wire from long leg to Pin 13

Step 2: Place the button on the breadboard
- Button legs straddle the center gap of the breadboard
- One leg to 5V rail
- Opposite leg to Pin 8 and also to ground through the 10k resistor

Step 3: Wire ground rail to Arduino GND

Step 4: Wire 5V rail to Arduino 5V

Step 5: Plug in USB

Watch for this: students often connect both legs of the button on the same side of the breadboard gap. The button will always read as pressed. Make sure the legs straddle the gap.

#### Doing it with virtual:

Step 1: Add Arduino Uno, breadboard, LED, 220Ω resistor, push button, 10kΩ resistor

Step 2: Wire LED
- LED anode to Pin 13
- LED cathode to 220Ω resistor
- Resistor to ground rail

Step 3: Wire button
- One terminal to 5V
- Same terminal row to Pin 8
- Pin 8 row also connects through 10k resistor to ground
- Other terminal to ground

Step 4: Click Code, select Text

### Write Code Together (20 minutes)

Code Reference: See `/code_examples/lesson_03_button_led.ino`

Build this line by line with the class:

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

Go through each part:

Variables at the top: we name our pins so the code is readable. If the button moves to a different pin, we only change one number at the top instead of hunting through the whole code.

pinMode(buttonPin, INPUT): this time we are declaring a pin as INPUT instead of OUTPUT. The Arduino listens to this pin instead of sending signals from it.

digitalRead(buttonPin): reads whether the pin is HIGH or LOW right now and stores it in buttonState.

The if statement: if the button is pressed, turn the LED on. Otherwise turn it off. This is the first time the code makes a decision based on something happening in the real world.

Upload and test. Button pressed, LED on. Button released, LED off.

### Expirement Time (15 minutes)

Challenges:

1. Flip the behavior. Make the LED turn ON when the button is NOT pressed and OFF when it is pressed.
2. Add a second LED. Button pressed turns LED 1 on and LED 2 off. Button released flips them.
3. (Advanced) Can you make the LED blink while the button is held? (Hint: put a delay inside the if statement)

### Show and Tell (5 minutes)

Call on 2-3 students:
- Show your working circuit
- Point to the pull-down resistor and explain what it does in your own words
- Explain what digitalRead does

### Closing (5 minutes)

Review questions:
- What happens to a pin without a pull-down resistor?
- What is the difference between INPUT and OUTPUT in pinMode?
- What does digitalRead return?

Next week preview: Potentiometer. Instead of just HIGH or LOW, you will get a number from 0 to 1023 that changes as you turn a knob.

Cleanup:
- Unplug USB
- Keep circuits assembled, the button stays for next lesson

## Assessment

During Lesson:
- Did the student wire the pull-down resistor correctly?
- Does the button control the LED as expected?
- Can the student explain what the pull-down resistor does?

Exit Ticket:
1. Draw the button circuit from memory, including the pull-down resistor
2. What would happen if you removed the pull-down resistor?
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have a working button circuit and can explain why the pull-down resistor is there

## Common Issues

### Button always reads HIGH
- Both legs of the button are on the same side of the breadboard gap
- Make sure the button straddles the center gap

### Button never reads HIGH
- Button leg not connected to 5V
- Check the wire from 5V rail to the button terminal

### LED flickers randomly when button is not pressed
- Pull-down resistor missing or wired incorrectly
- Check that the 10k resistor connects Pin 8 to ground

### Code compiles but nothing happens
- Check pin numbers in code match the actual wiring
- Make sure pinMode has INPUT for the button pin not OUTPUT

## Other Situations

Need support:
- Pre-wire the button for them and let them focus on the code
- Use a different color wire for the pull-down resistor so it is easy to spot

Advanced:
- Can you make the button toggle the LED instead of hold? (LED stays on after one press, turns off after the next)
- What happens if you use INPUT_PULLUP instead of INPUT and remove the physical resistor?

## Teacher Notes

The pull-down resistor demo is the most important moment of this lesson. Build a circuit without one and show the random behavior first. Students remember the problem a lot better when they see it before they learn the fix.

The toggle challenge is harder than it looks. Don't push students toward it unless they finish everything else early. It requires tracking state between loops which is a new concept.

Timing:
- Concept and demo: 13 min
- Build: 20 min
- Code: 20 min
- Experiments: 15 min
- Buffer: 12 min for troubleshooting

Prepare:
- Test all buttons before the session
- Have both circuits ready, one with pull-down resistor and one without

*End of Lesson 3*