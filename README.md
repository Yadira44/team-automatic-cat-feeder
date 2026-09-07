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

## Future Improvements
- Adding an easier way to manipulate timing and power to the motor based on load of food could be a great addition. This could allow a more user-friendly way to choose feeding time regardless of coding background and way to help the motor based on cat food weight; some people may be using the product to feed more than one cat.
- Designing and 3D printing a custom cat feeder case would be ideal compared to the current cardboard feeder.

## Work Breakdown Chart
<img width="818" height="497" alt="Screenshot 2026-09-06 at 8 10 30 PM" src="https://github.com/user-attachments/assets/68e89390-2e14-496d-a9bb-35e89e4bcdf4" />

## Schematic
<img width="1238" height="744" alt="Screenshot 2026-09-06 at 8 05 49 PM" src="https://github.com/user-attachments/assets/e764e446-e189-4adc-8c44-2cbc326a8098" />

## Cat Feeder Wiring
<img width="857" height="883" alt="Screenshot 2026-09-06 at 8 07 40 PM" src="https://github.com/user-attachments/assets/b3f2c5b3-9f6d-4586-894e-645ed88e587c" />

## Final Version
<img width="822" height="659" alt="Screenshot 2026-09-06 at 8 08 42 PM" src="https://github.com/user-attachments/assets/7678d2d7-f42c-479f-aab9-abe79b593299" />

## Video Of Cat Feeder
<img width="182" height="324" alt="Adobe Express - 1777441803819622" src="https://github.com/user-attachments/assets/b552e9bf-210f-4307-9902-82d0088655d8" />

## 3D Print Prototype
<img width="496" height="507" alt="Screenshot 2026-09-06 at 8 26 38 PM" src="https://github.com/user-attachments/assets/0fce14db-0139-40e7-9df4-a36b6b92781b" />



