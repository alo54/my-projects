# Smart Plant Water Level Monitor

This project is a Smart Plant Water Level Monitor.
It allows you to track soil water levels remotely using an ESP32 microcontroller, a humidity sensor, a relational database (MySQL), a custom API, and a mobile application made with MIT App Inventor.

When the soil reaches a water level out of a normal range (either high or low), the system sends a notification to the phone, helping users keep their plants healthy.
## Description

The project consists of a small, solar-powered device enclosed in a custom 3D-printed case. The device includes a soil moisture sensor and an ESP32 microcontroller.

When the device is turned on, the ESP32 first connects to a predefined WiFi network. Once connected, it measures the soil’s moisture level using the soil moisture sensor. The sensor produces raw analog values in the range of 0–2048. To enable a more convenient and human-understandable representation, over 2,000 samples were collected and analyzed to normalize these raw values to a scale from 0 to 100.

The ESP32 then sends the normalized (percentage) value via a POST request to a webpage, which subsequently stores the data in a MySQL database.

Additionally, another webpage displays the recorded data in a table, ordered by date.

The Android application then utilizes a JavaScript API to retrieve the most recent sensor reading from the webpage. It checks whether this value falls within a normal range — which can be configured by the user, depending on the specific plant’s needs. If the soil moisture is outside this range, the application sends a pop-up notification to advise the user about their plant’s water status. It also displays a graph of the recent water levels.

## Features

- Measures soil water level in real time.
- Stores data in a MySQL database.
- API implemented in JavaScript.
- MIT App Inventor application for real-time alerts.
- Wireless communication (WiFi) through ESP32.
- Powered by solar-rechargeable batteries for energy independence.
- Encased in a custom 3D-printed enclosure for durability and protection.

## Technologies

- ESP32 (C++/Arduino)
- C++ for data analysis
- Soil moisture sensor (analog)
- Rechargeable battery and solar panel
- MySQL for data storage
- JavaScript API for retrieving data
- MIT App Inventor for UI
- WiFi for communication

## Contributors
- Alondra Valdivia Sánchez: ESP32 programming, database configuration, API design, App Inventor codeblocks.
- A. Saravia: 3D case design and printing, App Inventor UI, data collection, and logo design.
- J. Contreras: Webpage design, PlatformIO configuration, circuit design, and wiring.
