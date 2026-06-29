# Lesson 1 Blinking LED

Estimated Duration: ~90 minutes    
Prerequisites: First Lesson, so none

## Overview

The goal for this lesson is for the students to get their hands dirty with the physical components, either with the physical components or the online Tinkercad versions. They should all be able to light up their LEDs by the end of the session and have some understanding of how they lit up.

## Learning goals

Students will learn:
- The main parts of the Arduino kit
- Basic electrical safety rules
- How to build an LED circuit on a breadboard or on TinkerCAD
- How to upload and test code on an Arduino board or run simulation
- How to edit code to change LED patterns

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 1 LED (any color)
- 1 220Ω resistor (red-red-brown stripes)
- 2 Jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with Tinkercad, each student will need:
- Computer
- Internet
- TinkerCAD account

### The Physics (Keep it simple)
- Quick note on Ohm's Law: V = I * R.
- The Arduino sends out 5V, but our LED only needs about 2V. The resistor is there to absorb the leftover 3V so the LED doesn't burn out.
- Remind them: without this math, the hardware wouldn't last five minutes.

## Before Lesson

For Physical Setup:
- Test all LEDs work
- Arduino IDE installed on all computers
- Have spare parts (LEDs, wires) ready
- Have example circuit ready to show
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- All students have TinkerCAD accounts created
- Test that TinkerCAD loads on all computers
- Have example circuit ready to show
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- Let the teacher let one student change the delay(1000) to delay(50).

## Lesson Plan

### Opening (5 minutes)

Show working example (physical or TinkerCAD projected)

Explain:
- What Arduino is and why it's useful
- What components they'll use today
- Answer initial questions

### Safety & Setup (5 minutes)

Four Safety Rules:
1. Follow instructions exactly - don't connect things randomly
2. Unplug if something smells wrong
3. Do NOT power the circuit before getting it checked
4. Ask questions - no questions are stupid

Component Check:
Have students hold up each part to confirm they have everything:
- Arduino board
- Breadboard
- LED
- Resistor
- Wires

### Understanding the LED (8 minutes)

Explain LED:
- LED = Light Emitting Diode
- Long leg (anode) = positive, electricity goes in
- Short leg (cathode) = negative, electricity goes out

Check: Students identify long/short legs and their purpose

### Build the Circuit (25 minutes)

Circuit Reference: See `/schematic_examples/lesson_01_circuit_breadboard.png` for visual guide

Demonstrate each step with a projector/camera. Students copy. Check everyone before the next step.

#### Doing it with real parts:

Step 1: LED across breadboard gap
- Long leg in Row 10, LEFT side
- Short leg in Row 10, RIGHT side

Step 2: Resistor
- One leg to LED short leg (Row 10, right)
- Other leg to ground rail (blue or rail with negative symbol)

Step 3: Wire LED to Pin 13
- Red wire from LED long leg - Arduino pin 13

Step 4: Wire Ground
- Black wire from ground rail - Arduino GND

Step 5: Plug in USB
- Check all circuits first
- Then plug USB from Arduino to computer

#### Doing it with virtual:

Step 1: Create new circuit, name "Lesson 1 - Blinking LED"

Step 2: Add components
- Arduino Uno R3
- Breadboard
- LED
- Resistor (220Ω)

Step 2b: Set resistor value
- Click on resistor
- In properties panel, set to 220Ω (or 220 ohms)

Step 3: Connect
- LED anode - Breadboard row 10, left
- LED cathode - Breadboard row 10, right
- Resistor: one end to LED cathode row, other to ground rail
- Wire: LED anode row - Arduino pin 13
- Wire: Ground rail - Arduino GND

Step 4: Click "Code" - Select "Text"

 

### The Logic: Setup vs. Loop
- void setup(): This runs once when you plug it in. It's like the "Pre-flight Checklist" for a pilot. We tell the Arduino that Pin 13 is an OUTPUT.
- void loop(): This runs forever. It's the robot's "Brain" repeating instructions until the power is cut.

### Write Code Together (20 minutes)

Code Reference: Complete code can be viewed at `/code_examples/lesson_01_blink.ino`

Type ONE LINE at a time. Check everyone's screen after each line.

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

Watch for common errors:
- Missing semicolons (;)
- Wrong capitalization
- Missing curly braces ({ })

### Upload & Test (10 minutes)

#### Physical Arduino:
1. Tools - Board - Arduino Uno
2. Tools - Port - Choose "Arduino" or "USB"
3. Click Upload button (arrow)
4. Wait for "Done uploading"

LED should blink on/off every second

#### TinkerCAD:
1. Click "Start Simulation"
2. LED should blink

Celebrate each working circuit!

### Explain the Code (10 minutes)

Go through code line by line:

- `void setup()` - Runs once at start
- `pinMode(13, OUTPUT)` - Pin 13 controls LED
- `void loop()` - Runs forever
- `digitalWrite(13, HIGH)` - Turn LED on
- `delay(1000)` - Wait 1 second (1000 milliseconds)
- `digitalWrite(13, LOW)` - Turn LED off
- `delay(1000)` - Wait 1 second, then repeat

Key concept: Code is instructions Arduino follows exactly, forever

### Experiment Time (12 minutes)

Challenges:

1. Try changing both 1000s to 100. What happens?
2. Try changing the first 1000 to 2000. What happens?
3. (Optional) Try to make the LED blink 3 times fast, pause, then repeat.

Key learning: Changing the numbers changes the behavior

### Closing (5 minutes)

Review questions:
- What does digitalWrite(13, HIGH) do?
- What does delay(1000) do?
- Difference between setup and loop?

Next week preview:
LED patterns - fast, slow, fast. Create your own pattern like morse code.

Cleanup:
- Unplug USB
- Keep circuits assembled (or carefully disassemble)

## Assessment

During Lesson:
- Can students identify LED legs?
- Is the circuit built correctly?
- LED blinks?
- Can explain changes after editing delay values?

Exit Ticket:
1. One thing learned
2. One question remaining
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have working blinking LED

## Common Issues

### LED doesn't light

Physical:
- LED backwards? (long leg to pin 13)
- Resistor to ground?
- Wires fully inserted?
- Try different LED
- USB plugged in?

TinkerCAD:
- Check connections
- LED anode/cathode correct?
- Restart simulation

### Errors

- Typos? (case-sensitive)
- Missing semicolons?
- Curly braces match?

### Can't upload

- Wrong port?
- USB loose?
- Wrong board selected?
- Try different USB port

### Code uploads but no blink

- Pin 13 in code?
- Rebuild circuit
- Built-in LED blinks? (If yes, circuit problem)

## Teacher Notes

Timing:
- Building takes 25-30 min
- Buffer 10-15 min for troubleshooting

Prepare:
- Test all materials before the session starts
- Make sure Arduino IDE or Tinkercad is available on everyone's computer
- TinkerCAD or physical example ready

*End of Lesson 1*