# Autonomous Rover

Arduino project that aims to create a rover that can navigate using relative positioning from initial location (origin) to a location expressed by a position vector while avoiding obsticles

## Hardware

- Arduino Uno
- 2x HC-SR04 Ultrasonic distance sensors (1 front 1 back)
- motor control for each side of the rover (in this case a motor per wheel but all 4 connected to one two channel H-Bridge
- Code wheels with Optical interupt transistors on each wheel to sense rotation speed
