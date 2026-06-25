# MedVault – Affordable AI-IoT Medicine Box

## Table of Contents
1. Introduction
2. Problem Statement
3. Objectives
4. System Overview
5. Architecture
6. Hardware Components
7. Software Components
8. Working Principle
9. ESP32 Logic
10. RTC Logic
11. Servo Control Logic
12. Reed Switch Logic
13. OLED Display Logic
14. Firebase Integration
15. Android Application Workflow
16. Data Flow
17. Scheduling System
18. Alert System
19. Remote Monitoring
20. Experimental Design
21. Testing Methodology
22. Calibration and Configuration
23. Results and Discussion
24. Advantages
25. Limitations
26. Future Scope
27. Troubleshooting
28. Viva Questions and Answers
29. Conclusion

---

# 1. Introduction

MedVault is an affordable AI-IoT based medicine management system designed to improve medication adherence. The project combines ESP32, RTC, Servo Motors, Reed Switches, OLED Display, Firebase and Android application support.

The primary purpose of the system is to ensure that medicines are taken on time while providing monitoring and notification capabilities.

---

# 2. Problem Statement

Medication non-adherence is one of the biggest healthcare challenges.

Common problems:

- Forgetting medicine timings
- Missing doses
- Taking duplicate doses
- Lack of caregiver monitoring
- Difficulty managing multiple medicines
- Lack of reminders for elderly patients

MedVault addresses these issues using automation and IoT.

---

# 3. Objectives

- Improve medication adherence
- Reduce missed doses
- Provide automated dispensing
- Enable caregiver monitoring
- Provide reminder notifications
- Create a low-cost healthcare solution
- Support future AI-based prediction systems

---

# 4. System Overview

The system consists of:

- ESP32 Controller
- DS3231 RTC Module
- 6 Servo Motors
- Reed Switches
- OLED Display
- Firebase Cloud
- Android Mobile Application
- Audio Reminder System

---

# 5. Architecture

```text
Android App
     |
Firebase Cloud
     |
    ESP32
     |
 ----------------------
 | | | | | |
 S1 S2 S3 S4 S5 S6
     |
 Medicine Compartments
```

---

# 6. Hardware Components

## ESP32

Responsibilities:

- Main controller
- WiFi communication
- Scheduling execution
- Servo control
- Cloud communication

Why ESP32?

- Built-in WiFi
- Built-in Bluetooth
- Multiple GPIO pins
- Low cost
- High performance

---

## DS3231 RTC

Responsibilities:

- Accurate time keeping
- Battery backup support
- Time synchronization

Benefits:

- High accuracy
- Reliable scheduling
- Works during power loss

---

## Servo Motors

Total: 6

Purpose:

- Open medicine compartment
- Close medicine compartment
- Controlled by ESP32

Operation:

- 0° = Closed
- 90° = Open

---

## Reed Switches

Purpose:

- Detect compartment opening
- Confirm medicine access
- Generate feedback to ESP32

---

## OLED Display

Purpose:

- Show current time
- Show medicine schedules
- Display system status

---

## Capacitor

1000uF capacitor is used for:

- Voltage stabilization
- Preventing servo voltage dips
- Improving reliability

---

# 7. Software Components

## Firmware

Written using:

- Arduino IDE
- C++
- ESP32 Libraries

Responsibilities:

- Scheduling
- RTC reading
- Servo control
- Cloud communication

---

## Mobile Application

Responsibilities:

- User scheduling
- Notifications
- Caregiver monitoring
- Data visualization

---

## Firebase

Responsibilities:

- Store schedules
- Store logs
- Cloud synchronization
- Remote monitoring

---

# 8. Working Principle

Step 1:
User enters medicine schedule.

Step 2:
Data stored in Firebase.

Step 3:
ESP32 downloads schedule.

Step 4:
RTC continuously tracks time.

Step 5:
When scheduled time arrives:

- Buzzer activates
- OLED updates
- Notification sent

Step 6:
Servo opens medicine compartment.

Step 7:
Reed switch checks access.

Step 8:
Data logged.

---

# 9. ESP32 Logic

ESP32 performs:

- Time monitoring
- Servo control
- Firebase synchronization
- Alert management
- Data logging

Pseudo Logic:

```text
Read RTC
Check Schedule
If Match:
 Open Compartment
 Trigger Alert
 Wait For User
 Log Status
```

---

# 10. RTC Logic

RTC continuously provides:

- Hours
- Minutes
- Seconds

Benefits:

- Accurate timing
- Power failure protection

---

# 11. Servo Logic

Servo sequence:

1. Receive command
2. Rotate to 90°
3. Wait for medicine access
4. Rotate back to 0°

---

# 12. Reed Switch Logic

States:

Closed = Not accessed

Open = Access detected

Purpose:

- Confirm intake event
- Generate logs

---

# 13. OLED Display Logic

Display Contents:

- Current Time
- Upcoming Medicine
- Alert Messages
- System Status

---

# 14. Firebase Integration

Stores:

- User profiles
- Medicine schedules
- Intake history
- Notifications

Benefits:

- Cloud backup
- Remote monitoring
- Multi-device access

---

# 15. Android Application Workflow

User:

1. Login
2. Add medicine
3. Configure timing
4. Save schedule

Firebase:

- Receives data
- Stores data

ESP32:

- Fetches data
- Executes schedule

---

# 16. Data Flow

```text
User
 |
App
 |
Firebase
 |
ESP32
 |
Servo + OLED + Alerts
 |
Logs
 |
Firebase
```

---

# 17. Scheduling System

Parameters:

- Medicine name
- Time
- Frequency
- Quantity

Supported:

- Daily schedules
- Weekly schedules
- Multiple reminders

---

# 18. Alert System

Types:

- OLED Alert
- Audio Alert
- Mobile Notification
- Caregiver Notification

Escalation:

- Missed dose detection
- Repeated reminders

---

# 19. Remote Monitoring

Caregiver can:

- View medicine status
- Track missed doses
- Receive alerts

---

# 20. Experimental Design

Tests Conducted:

- Power test
- Connectivity test
- End-to-end workflow test
- User simulation

Metrics:

- Accuracy
- Response time
- Reliability

---

# 21. Testing Methodology

## Power Test

Verify:

- Stable voltage
- Servo performance

## Connectivity Test

Verify:

- Firebase communication
- WiFi stability

## End-to-End Test

Schedule -> Alert -> Intake -> Logging

---

# 22. Calibration and Configuration

Sensor Calibration:

- Reed switch calibration
- Timing calibration

Network Configuration:

- WiFi setup
- Firebase linking

User Configuration:

- Schedule creation
- Caregiver setup

---

# 23. Results and Discussion

Observed Benefits:

- Improved adherence
- Reduced missed doses
- Better monitoring
- Reliable scheduling

---

# 24. Advantages

- Affordable
- Accurate
- Expandable
- IoT enabled
- User friendly
- Scalable

---

# 25. Limitations

- Internet dependency for cloud features
- Requires power supply
- Initial setup complexity

---

# 26. Future Scope

- AI prediction engine
- Machine learning personalization
- Voice assistants
- Hospital integration
- EHR integration
- SMS fallback mode
- GPS emergency alerts
- Biometric authentication

---

# 27. Troubleshooting

## RTC Not Detected

Check:
- Wiring
- I2C address
- Battery

## Servo Not Moving

Check:
- Power supply
- PWM pin
- Wiring

## Firebase Error

Check:
- Internet
- Authentication
- Database rules

---

# 28. Viva Questions and Answers

## Q1 Why ESP32?

Because it provides WiFi, Bluetooth, multiple GPIOs and high performance.

## Q2 Why DS3231?

Because it provides accurate real-time tracking with battery backup.

## Q3 Why Servo Motors?

To precisely open and close medicine compartments.

## Q4 Why Reed Switches?

To detect compartment access.

## Q5 Why Firebase?

For cloud synchronization and remote monitoring.

## Q6 What happens if medicine is missed?

System triggers repeated alerts and caregiver notifications.

## Q7 Why OLED?

To provide local visual information.

## Q8 What is medication adherence?

Taking medicine at the correct time and dosage.

## Q9 What are the benefits of IoT?

Remote monitoring and real-time synchronization.

## Q10 What is the role of AI in MedVault?

Future prediction of user behavior and missed doses.

## Q11 How does the system know current time?

Using DS3231 RTC.

## Q12 Why use cloud storage?

For backup and remote accessibility.

## Q13 How are compartments controlled?

Using servo motors connected to ESP32.

## Q14 What happens during power loss?

RTC continues tracking time using battery backup.

## Q15 What is the main goal of MedVault?

Improve medication adherence.

---

# 29. Conclusion

MedVault demonstrates a practical, affordable, and scalable medicine management system. By combining ESP32, RTC scheduling, servo-controlled compartments, reed-switch monitoring, OLED display, Firebase connectivity, and mobile application support, the system improves medicine adherence and enables better healthcare monitoring. The project provides a strong foundation for future AI-driven healthcare solutions.
