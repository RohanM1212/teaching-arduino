# Lesson 5: Capstone 1 — Build Your Own Circuit

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lessons 1 through 4 — students should be comfortable with LEDs, buttons, and potentiometers

## Overview

No instructions this lesson. Students use everything from lessons 1 through 4 and build whatever they want. Some will build something simple. Some will surprise you. Both are fine.

## Learning goals

Students will learn:
- How to design a circuit from scratch using what they already know
- How to write code for a problem they came up with themselves
- How to explain every decision they made
- How to debug their own circuit when something does not work

## Materials

If working with physical parts, each student will need:
- 1 Arduino Uno R3
- 1 Breadboard
- Multiple LEDs (different colors if possible)
- Multiple 220Ω resistors
- 1 Push button
- 1 10kΩ resistor (pull-down)
- 1 Potentiometer
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account

### The Requirements (go over these at the start)
- Must use at least 2 components from the lessons
- Code must have at least one if statement
- They have to be able to explain what every part does and why it is there

### Learning Moment
- During the build phase, when a student is stuck, ask questions instead of fixing it. "What do you want this part to do?" works better than just showing them.

## Before Lesson

For Physical Setup:
- Have all components sorted so students are not hunting for parts
- Have working examples from lessons 1 through 4 saved in case students need a reference
- Do NOT have a pre-built circuit ready. There is no example to show this time.
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have lessons 1 through 4 saved in TinkerCAD to reference
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

## Lesson Plan

### Opening (5 minutes)

Tell the class what today is. No instructions, no circuit to copy. They are building whatever they want using what they already know.

Ask: "What is something you wanted to make during one of the last four lessons but we did not have time for?"

Let a few students share. Gets ideas going before the brainstorm.

### Direction and Requirements (15 minutes)

Go over what they have available:

Components they know:
- LEDs
- Push button
- Potentiometer
- Resistors

Code they know:
- digitalWrite and digitalRead
- analogRead and analogWrite
- delay
- if and else statements
- Variables

Go over the three requirements from the requirements section above.

Show one example idea without building it. Something like: "You could make a nightlight that turns on when a button is pressed and gets brighter the more you turn the potentiometer." Then immediately say that is just one idea and they should come up with their own.

One rule: they cannot just copy the code from a previous lesson. Has to be something new even if it uses the same concepts.

### Brainstorm (10 minutes)

Before anyone touches a component, every student writes down 3 ideas. Does not have to be good ideas. Just 3 different things.

Walk around while they write. If a student is stuck, ask:
- "Is there anything from real life you could simulate with an LED and a button?"
- "What was the coolest part of the last four lessons?"
- "What would you build if you had more components?"

After 10 minutes each student picks one and circles it. That is what they are building.

If two students pick the same idea that is fine. Their code and wiring will end up different anyway.

### Build (60 minutes)

Students build. Walk around and help.

When a student is stuck, ask questions instead of fixing it:
- "What do you want this part to do?"
- "What does this line of code tell the Arduino?"
- "What have you already tried?"

Only step in and show them directly if they have been stuck on the same problem for more than 5 minutes and questions are not helping.

Students who finish early: ask them to add one more feature. Used a button? Can they add the potentiometer? Have two LEDs? Can they add a third with different behavior?

Students who are struggling: simplify with them. Ask what the minimum version of their idea looks like. Build that first and add to it after.

Students who copied a previous lesson: ask them to change at least three things so it becomes their own.

With 10 minutes left, tell the class to stop adding new features and get whatever they have working. Loose wires and half finished features do not help at demo time.

### Demo Time (10 minutes)

Go around the room. Every student gets 60 seconds to:
- Show their circuit working
- Explain one decision they made
- Say one thing they would add if they had more time

Don't grade on complexity. Grade on whether they can explain what they built and why.

### Closing (5 minutes)

Ask the class:
- What was the hardest part about building with no instructions?
- Did anyone build something they did not think they could?
- What component do you wish you had?

Next week preview: Servo motor. Instead of LEDs turning on and off, something actually moves.

Cleanup:
- Unplug USB
- Disassemble carefully and return components to the bins

## Assessment

During Lesson:
- Did the student design their own circuit or copy a previous lesson?
- Does the circuit meet the three requirements?
- Can they explain what their code does line by line?

Exit Ticket:
1. Draw your circuit from memory
2. One thing you figured out on your own today
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: Every student has a working circuit they designed themselves and can explain

## Common Issues

### Student cannot think of an idea
- Start smaller. Ask them to make an LED do something it has not done in any previous lesson.
- Give them the nightlight idea as a starting point if they are completely stuck

### Student copies a previous lesson exactly
- Ask them to change the behavior in at least three ways
- "What would make this yours instead of mine?"

### Circuit works but student cannot explain it
- Go line by line with them
- Ask them to read each line out loud and say what they think it does

### Student finishes in 20 minutes
- Ask what they would add if they had one more component
- Can they make it work without the button?

## Other Situations

Need support:
- Let them work with a partner
- Give them a starting circuit with one component wired and let them add to it

Advanced:
- Can you make your circuit do three different things depending on how far the potentiometer is turned?
- Can you make the button toggle something instead of just holding it on?

## Teacher Notes

The brainstorm phase matters more than it seems. Students who skip straight to building usually get stuck faster because they did not think through what they wanted to make. Hold the line on 3 ideas before anyone touches a component.

The demo at the end matters. Even if a circuit barely works, having every student present makes them feel like they built something real. Keep it short but do not skip it.

Your job in this lesson is different from the others. You are not teaching new material. You are asking good questions and getting out of the way.

Timing:
- Opening: 5 min
- Direction and requirements: 15 min
- Brainstorm: 10 min
- Build: 60 min
- Demo: 10 min
- Closing: 5 min
- No buffer. If something runs over, take it from the build phase not the demo.

Prepare:
- Sort all components before the session
- Have lessons 1 through 4 saved and ready to reference

*End of Lesson 5*