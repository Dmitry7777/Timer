#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "timer.h"

// Define pin assignments
#define LED_PIN 13
#define BUZZER_PIN 8

// Callback functions for output devices
void turnOnLed(uint8_t deviceId) {
    digitalWrite(deviceId, HIGH); // Assuming LED is active high
}

void turnOffLed(uint8_t deviceId) {
    digitalWrite(deviceId, LOW);
}

void playSound(uint8_t deviceId) {
    tone(deviceId, 440, 1000); // Play a tone for 1 second
}

// Instantiate objects
LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD address and dimensions
time myTimer; // Timer object

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    // Register output devices with the timer
    myTimer.addOutputDevice(LED_PIN, turnOnLed); // Register LED
    myTimer.addOutputDevice(BUZZER_PIN, playSound); // Register buzzer

    // Initialize the LCD display
    lcd.init();
    lcd.backlight();

    // Show the initial message
    lcd.setCursor(0, 0);
    lcd.print("Industrial Timer");

    // Start the timer and notify output devices
    myTimer.startTimer(LED_PIN, BUZZER_PIN);
}

void loop() {
    // Update the display with current time
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    lcd.print(myTimer.getHours());
    lcd.print(":");
    lcd.print(myTimer.getMinutes());
    lcd.print(":");
    lcd.print(myTimer.getSeconds());

    // Simulate a delay or wait for real-time updates
    delay(1000);
}
