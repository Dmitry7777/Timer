#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "timer.h"

LiquidCrystal_I2C lcd(0x27, 20, 4); // LCD address and dimensions
time myTimer; // Timer object

void setup() {
    lcd.init(); // Initialize the LCD display
    lcd.backlight(); // Turn on the backlight

    // Show the initial message
    lcd.setCursor(0, 0); // Cursor position at the top left
    lcd.print("Industrial Timer"); // Title

    myTimer.startTimer(); // Start the timer
}

void loop() {
    lcd.clear(); // Clear the screen
    lcd.setCursor(0, 0); // Move cursor to the beginning

    // Display the current time
    lcd.print("Time: "); // Label for time
    lcd.print(myTimer.getHours());
    lcd.print(":");
    lcd.print(myTimer.getMinutes());
    lcd.print(":");
    lcd.print(myTimer.getSeconds());

    delay(1000); // Refresh every second
}
