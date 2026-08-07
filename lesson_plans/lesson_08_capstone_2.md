# Lesson 8: Capstone 2 — Build Your Own Circuit

Estimated Duration: ~90 minutes
Age Group: 11-14 years old
Prerequisites: Lessons 1 through 7 — students should be comfortable with LEDs, buttons, potentiometers, servos, switch statements, and loops

## Overview

Same as capstone 1, but harder. Students have more tools now and the bar is higher. No instructions, no circuit to copy. They build whatever they want using everything from lessons 1 through 7.

## Learning goals

Students will learn:
- How to design a more complex circuit using everything they know so far
- How to write code that uses at least one loop or switch statement
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
- 1 Servo motor
- 1 100 microfarad capacitor (polarized)
- Several jumper wires
- 1 USB cable
- Computer with Arduino IDE installed

If working with TinkerCAD, each student will need:
- Computer
- Internet
- TinkerCAD account
- No capacitor needed in TinkerCAD

### The Requirements (go over these at the start)
- Must use at least 3 components
- Code must have at least one switch statement or one loop
- Must be able to explain what every part does and why it is there
- Cannot build the same thing they built in capstone 1

### Learning Moment
- During the build phase, when a student is stuck, ask questions instead of fixing it. "What do you want this part to do?" works better than just showing them.

## Before Lesson

For Physical Setup:
- Have all components sorted so students are not hunting for parts
- Have working examples from lessons 1 through 7 saved in case students need a reference
- Do NOT have a pre-built circuit ready. There is no example to show this time.
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

For TinkerCAD:
- Have lessons 1 through 7 saved in TinkerCAD to reference
- (Optional) Complete pre-lesson survey (https://forms.gle/HJoWXzzGJgc2NwMN8)

## Lesson Plan

### Opening (5 minutes)

Tell the class what today is. Same deal as capstone 1 but they have a lot more to work with now.

Ask: "What is something you wanted to build in capstone 1 but didn't have the components or knowledge for yet?"

Let a few students share. Gets ideas going before the brainstorm.

### Direction and Requirements (15 minutes)

Go over what they have available now:

Components they know:
- LEDs
- Push button
- Potentiometer
- Servo motor
- Resistors and capacitor

Code they know:
- digitalWrite and digitalRead
- analogRead and analogWrite
- delay and millis()
- if and else statements
- switch statements
- for loops and while loops
- Variables
- map()

Go over the four requirements from the requirements section above.

Show one example idea without building it. Something like: "You could make a servo that sweeps to a different angle depending on which mode you are in, controlled by a button cycling through a switch statement." Then immediately say that is just one idea and they should come up with their own.

One rule: they cannot just copy the code from a previous lesson. Has to be something new even if it uses the same concepts.

### Brainstorm (10 minutes)

Before anyone touches a component, every student writes down 3 ideas. Does not have to be good ideas. Just 3 different things.

Walk around while they write. If a student is stuck, ask:
- "What did you wish you could add to capstone 1 but couldn't?"
- "What was the coolest thing you built in lessons 6 or 7?"
- "What would you build if you had even more components?"

After 10 minutes each student picks one and circles it. That is what they are building.

If two students pick the same idea that is fine. Their code and wiring will end up different anyway.

### Build (60 minutes)

Students build. Walk around and help.

When a student is stuck, ask questions instead of fixing it:
- "What do you want this part to do?"
- "What does this line of code tell the Arduino?"
- "What have you already tried?"

Only step in and show them directly if they have been stuck on the same problem for more than 5 minutes and questions are not helping.

Students who finish early: ask them to add one more feature. Only using LEDs and a button? Can they add the servo? Have a switch statement with two cases? Can they add a third?

Students who are struggling: simplify with them. Ask what the minimum version of their idea looks like. Build that first and add to it after.

Students who copied a previous lesson or capstone 1: ask them to change at least three things so it becomes their own.

With 10 minutes left, tell the class to stop adding new features and get whatever they have working. Loose wires and half finished features do not help at demo time.

### Demo Time (10 minutes)

Go around the room. Every student gets 60 seconds to:
- Show their circuit working
- Explain one decision they made
- Say one thing they would add if they had more time

Don't grade on complexity. Grade on whether they can explain what they built and why.

### Closing (5 minutes)

Ask the class:
- What was harder about this capstone compared to the first one?
- Did anyone use a component they had not touched since the lesson it was introduced?
- What would you build if you had any component you wanted?

Cleanup:
- Unplug USB
- Disassemble carefully and return components to the bins
- Be careful with the servo wires and the capacitor legs

## Assessment

During Lesson:
- Did the student design their own circuit or copy a previous lesson?
- Does the circuit meet all four requirements?
- Can they explain what their code does line by line?

Exit Ticket:
1. Draw your circuit from memory
2. One thing you figured out on your own today
3. (Optional) Complete post-lesson survey (https://forms.gle/KjvaqDAQ5QRLcHXCA)

Success: Every student has a working circuit they designed themselves and can explain

## Common Issues

### Student cannot think of an idea
- Start smaller. Ask them to take something from capstone 1 and add a servo or a loop to it
- Give them the mode-switching servo idea as a starting point if they are completely stuck

### Student copies capstone 1 or a previous lesson
- Ask them to change the behavior in at least three ways
- "What would make this yours instead of something we already built?"

### Circuit works but student cannot explain it
- Go line by line with them
- Ask them to read each line out loud and say what they think it does

### Student finishes in 20 minutes
- Ask what they would add if they had one more component
- Can they add a third mode to their switch statement?

## Other Situations

Need support:
- Let them work with a partner
- Give them a starting circuit with two components wired and let them add to it

Advanced:
- Can you make your circuit do four different things with a switch statement?
- Can you use millis() instead of delay() so the button stays responsive the whole time?

## Teacher Notes

Hold the line on the brainstorm. Same as capstone 1, students who skip it get stuck faster. 3 ideas before anyone touches a component.

The "cannot repeat capstone 1" rule needs a judgment call on your end. A nightlight in capstone 1 and a mood lamp in capstone 2 might be too similar. Use your read on the student. The spirit of the rule is that they have to actually use something new from lessons 5 through 7.

The demo matters. Even if a circuit barely works, having every student present makes them feel like they built something real. Keep it short but do not skip it.

Your job in this lesson is the same as capstone 1. You are not teaching new material. You are asking good questions and getting out of the way.

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
- Have lessons 1 through 7 saved and ready to reference

*End of Lesson 8*