**Automatic Billing Machine**

**Overview**

This project aims to automate the billing process in supermarkets using RFID technology and NodeMCU. The system detects products placed in a shopping trolley using an RFID reader, displays the product price on an LCD, and allows verification of the bill at the exit via a website. This project was developed as a mini-project for the Electronics Telecommunication Engineering Department at AISSMS Institute of Information Technology, Pune.

**Features**

Automatic Product Detection: Uses an EM-18 RFID reader to detect products placed in the trolley.

Real-time Billing Display: LCD displays the name and price of each product added to the trolley.

Dynamic Price Update: Automatically updates the total price as items are added or removed.

Cloud Verification: Allows the shopkeeper to verify the bill using a website.

**Hardware Components**

EM-18 RFID Reader Module

RFID Cards

16x2 LCD Display

NodeMCU - ESP8266 Wi-Fi Development Board

Buzzer

Push Buttons

LEDs

Resistors

Cables and Connectors

Software Requirements

Arduino IDE

ESP8266WiFi Library

LiquidCrystal_I2C Library

Circuit Diagram

Block Diagram

**Working**

Initialization: The system initializes by displaying a welcome message on the LCD.

Product Scanning: Products are detected using the RFID reader and their details are displayed on the LCD.

Price Calculation: The total price is updated as products are added or removed.

Bill Generation: The final bill is generated and can be verified by the shopkeeper via a website.
