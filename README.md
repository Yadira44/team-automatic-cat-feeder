# team-automatic-cat-feeder
An automated 2-stage rotary cat feeder designed to dispense scheduled meals using an embedded RTC module, Arduino Uno, and NPN transistor motor control circuit. Built for EENG 1910 at the University of North Texas.

## System Architecture

- **Microcontroller:** Elegoo Arduino Uno R3 (C++)
- **Timekeeping:** DS3231 I2C Real-Time Clock (RTC) module with CR2032 coin cell backup
- **Actuation:** 12V 3 RPM Geared DC Motor driven via NPN transistor switch (2N2222)
- **Circuit Protection:** Flyback diode across motor terminals to suppress inductive back-EMF spikes
- **Power Supply:** 9V DC battery pack

## Hardware Schematics & Operation

The system compares real-time clock data against predefined daily feeding schedules (e.g., 9:00 AM, 3:00 PM). Upon match:
1. Arduino pulls Digital Pin 8 HIGH, biasing the NPN transistor base.
2. The transistor conducts, driving the 3 RPM DC motor for a calibrated duration (~15s) based on food payload mass.
3. The flat carousel rotates 45°, dropping the food compartment over the lower discharge chute.

## Key Challenges Solved

- Added a flyback diode in parallel with the motor to protect the microcontroller from voltage transients during motor shutoff.
- Addressed fragile soldered lead joints on the DC motor by stress-testing wires and applying hot-glue mechanical anchoring.
- Implemented `millis()` time tracking in C++ to prevent delay loops from blocking RTC time updates.

## Schematic
<img width="1238" height="744" alt="Screenshot 2026-09-06 at 8 05 49 PM" src="https://github.com/user-attachments/assets/e764e446-e189-4adc-8c44-2cbc326a8098" />

## Cat Feeder Wiring
<img width="857" height="883" alt="Screenshot 2026-09-06 at 8 07 40 PM" src="https://github.com/user-attachments/assets/b3f2c5b3-9f6d-4586-894e-645ed88e587c" />

