# 6-DOF SG90 Robotic Arm Simulator

Static browser-based 3D simulator for an Arduino Uno robotic arm using six SG90 servos.

## Deploy to Vercel

This is a static site. No build command or framework is required.

- Framework Preset: Other
- Root Directory: `.`
- Build Command: leave blank
- Output Directory: `.`
- Install Command: leave blank

The entry page is `index.html`.

## Run locally

Open `index.html` in a modern browser. The Three.js library is loaded from jsDelivr, so an internet connection is required.

## Hardware

- Arduino Uno powered by USB
- Six SG90 servos powered by a separate regulated 5V 5A supply
- Servo signal pins: D2, D3, D4, D5, D6, D7
- Connect external supply GND to Arduino GND
- Do not connect the external +5V rail to the Uno 5V pin while USB is connected

See `SixDOF_SG90_Arm.ino` for the Arduino sketch. The browser simulator is visual only; it does not directly communicate with the physical Arduino.
