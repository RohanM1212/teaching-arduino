# Lesson 2: LED Patterns + Series vs. Parallel

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lesson 1 (Blinking LED) — students should have a working single LED circuit

## Overview

Last lesson we got one LED blinking. This lesson we will add more and figure out that the way you wire them completely changes how they behave.

## Learning goals

Students will learn:
- How series circuits work and why LEDs are dimmer inside of them
- How parallel circuits work and why each LED needs its own resistor
- How to control multiple LEDs using multiple pinMode and digitalWrite calls
- How to write an LED pattern that is intentional, not just random

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- 3 LEDs (different colors if possible, the brightness difference is more obvious)
- 3 220Ω resistors
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account

### The Physics (Keep it simple)
- The Arduino gives 5V. A red LED needs about 1.8V minimum to light up.
- In series, LEDs share that 5V so each one gets less. In parallel, each LED gets the full 5V.
- That is why the same components wired differently look completely different.

## Before Lesson

For Physical Setup:
- Build a series circuit (2 LEDs) and a parallel circuit (2 LEDs) ahead of time and have both ready to show side by side
- Have the lesson 1 blink code ready to reference for the series build section
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have both circuits built in TinkerCAD ahead of time
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

### Learning Moment
- When students see the parallel circuit for the first time, ask them why it is brighter before explaining anything.

## Lesson Plan

### Opening (5 minutes)

Show both pre-built circuits powered at the same time. Don't explain anything yet. Just let them look.

Ask: "These both have two LEDs and the same power source. Why is one brighter?"

Let them guess. Don't confirm anything yet. Tell them they'll figure out why by the end of the lesson.

### Review Lesson 1 (5 minutes)

Quick check before moving on:
- What does void setup() do?
- What does void loop() do?
- What does delay(1000) mean?

If most students remember, move on. If not, do a 2 minute recap before continuing. Don't spend long here.

### Concept: Series vs. Parallel (10 minutes)

Series:

Point to the series circuit. Electricity has only one road to travel. Both LEDs share the voltage. The Arduino gives 5V. The red LED has a forward voltage of about 1.8V, meaning that is the minimum it needs to light up. In a 2-LED series circuit, each LED gets roughly half of the available voltage. They do light up, but they are dim. Add a third LED and each one gets even less. You can see this in the images from when I built these circuits. If one LED breaks, the whole circuit goes dark. Same reason old Christmas lights would kill the whole string when one bulb died.

Parallel:

Each LED gets its own road. Each LED gets the full 5V. They are brighter and independent of each other. If one dies, the others keep running. This is how almost everything in real life is wired, your house, your phone, basically any device you can think of.

One thing to watch: if you add too many LEDs in parallel, the Arduino will try to pull more current than it can handle and it may pop a fuse or overheat. So just don't go crazy adding LEDs.

### Build Part 1: Series Circuit (15 minutes)

Goal: Two LEDs wired in series, both controlled by Pin 13

Circuit Reference: See `/schematic_examples/lesson_02_series_circuit.png`

#### Doing it with real parts:

Step 1: Place two LEDs on the breadboard
- LED1: long leg Row 5 left, short leg Row 5 right
- LED2: long leg Row 8 left, short leg Row 8 right

Step 2: Connect LEDs in series
- Wire from LED1 short leg (Row 5 right) to LED2 long leg (Row 8 left)

Step 3: Resistor
- One end to LED2 short leg (Row 8 right)
- Other end to ground rail

Step 4: Wire LED1 long leg to Pin 13

Step 5: Wire ground rail to Arduino GND

Step 6: Plug in USB

#### Doing it with virtual:
- Same connections, chain LED1 cathode to LED2 anode
- Resistor at end to ground
- LED1 anode to Pin 13

Code: Use the lesson 1 blink code. Both LEDs blink together since they share one path.

Ask students to look at the brightness and remember it. They are about to see something different.

### Build Part 2: Parallel Circuit (15 minutes)

Goal: Two LEDs wired in parallel, each on their own pin

Circuit Reference: See `/schematic_examples/lesson_02_parallel_circuit.png`

#### Doing it with real parts:

Step 1: Keep LED1 from before (Row 5)

Step 2: Add LED2 separately
- Long leg Row 8 left, short leg Row 8 right

Step 3: Each LED gets its own resistor to ground, two resistors total, one per LED

Step 4: LED1 long leg to Pin 12, LED2 long leg to Pin 13

Step 5: Both ground resistors to ground rail, ground rail to Arduino GND

#### Doing it with virtual:
- Each LED has its own path to ground
- LED1 anode to Pin 12, LED2 anode to Pin 13

Ask the same question: how bright are they now compared to before? Why?

### Write Code Together (20 minutes)

Code Reference: See `/code_examples/lesson_02_led_patterns.ino`

Build this together line by line:

void setup() {
  pinMode(11, OUTPUT);  // LED 1
  pinMode(12, OUTPUT);  // LED 2
  pinMode(13, OUTPUT);  // LED 3
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

Upload and run. Go through it line by line. Each LED turns on for 300ms then turns off before the next one turns on.

Then give them 10 minutes to write their own pattern. The only rule is they have to be able to explain why they wrote it the way they did.

If students freeze, suggest:
- All three blink together fast three times, then pause
- Alternate: LED1 on while LED2 is off, then flip
- Countdown: all three on, then two, then one, then all off

### Show and Tell (5 minutes)

Call on 2-3 students:
- Ask them to point to the line of code that controls LED 1
- Ask why they chose that delay value
- Ask the class what would happen if that delay was changed to 100

### Closing (5 minutes)

Review questions:
- Why were the LEDs dimmer in series?
- Why does each LED in parallel need its own resistor?
- Which would you use for a bedroom light?

Next week preview: Buttons. Instead of just watching the circuit run, you will be able to control it yourself.

Cleanup:
- Unplug USB
- Keep circuits if possible, buttons get added next lesson

## Assessment

During Lesson:
- Can the student wire a parallel circuit correctly?
- Do they understand why parallel is brighter?
- Did they write a pattern they can explain?

Exit Ticket:
1. Draw a series circuit and a parallel circuit (rough is fine, just show the concept)
2. One thing that surprised them this lesson
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: 90%+ students have a working parallel circuit and a pattern they can explain

## Common Issues

### LEDs not turning on in series
- Check LED orientation, both have to face the same direction
- Check the wire between LED1 cathode and LED2 anode, easy one to miss
- Series circuits are less forgiving of loose connections than parallel

### One LED works, the other doesn't in parallel
- Each LED needs its own resistor, check that both are there
- Test each LED's connection to its pin independently
- Swap the non-working LED to rule out a dead component

### Code runs but wrong LED blinks
- Check that pin numbers in the code match the actual wiring
- Easier to move the wire on the breadboard to match the code than rewrite the code

### Students finish early
- Can they make the pattern spell a letter in morse code?
- Can they make it look like a heartbeat, fast-fast-pause?
- Can they add a fourth LED?

## Other Situations

Need support:
- Pre-draw the parallel circuit and let them copy it
- Let them work in pairs for the build section
- Get the circuit working first, pattern second

Advanced:
- What happens with delay(0)?
- Can they make two LEDs blink at different speeds?
- What would happen if they wired 10 LEDs in series?

## Teacher Notes

Timing:
- Series build: 15 min
- Parallel build: 15 min
- Pattern coding: 20 min
- Buffer: 10 min for troubleshooting

Prepare:
- Have both circuits built and tested before the session
- TinkerCAD or physical examples ready

*End of Lesson 2*