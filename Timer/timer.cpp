#include "timer.h"

// Default constructor sets time to 00:00:00
time::time() : hours(0), minutes(0), seconds(0), running(false) {}

// Constructor with parameters
time::time(uint8_t hrs, uint8_t mins, uint8_t secs) : hours(hrs), minutes(mins), seconds(secs), running(false) {}

// Setting time
void time::setTime(uint8_t hrs, uint8_t mins, uint8_t secs) {
    hours = hrs;
    minutes = mins;
    seconds = secs;
}

void time::setHours(uint8_t hrs) {
    hours = hrs;
}

void time::setMinutes(uint8_t mins) {
    minutes = mins;
}

void time::setSeconds(uint8_t secs) {
    seconds = secs;
}

// Increasing time
void time::increaseTime(uint8_t button) {
    switch(button) {
        case 1: // Increase hours
            if (hours == 23) {
                hours = 0;
            } else {
                ++hours;
            }
            break;
        case 2: // Increase minutes
            if (minutes == 59) {
                minutes = 0;
            } else {
                ++minutes;
            }
            break;
        case 3: // Increase seconds
            if (seconds == 59) {
                seconds = 0;
            } else {
                ++seconds;
            }
            break;
    }
}

// Decreasing time
void time::decreaseTime(uint8_t button) {
    switch(button) {
        case 1: // Decrease hours
            if (hours == 0) {
                hours = 23;
            } else {
                --hours;
            }
            break;
        case 2: // Decrease minutes
            if (minutes == 0) {
                minutes = 59;
            } else {
                --minutes;
            }
            break;
        case 3: // Decrease seconds
            if (seconds == 0) {
                seconds = 59;
            } else {
                --seconds;
            }
            break;
    }
}

// Starting the timer
void time::startTimer() {
    running = true;
}

// Stopping the timer
void time::stopTimer() {
    running = false;
}

// Delaying the timer
void time::delayTimer(uint8_t hrs, uint8_t mins, uint8_t secs) {
    // Logic for delaying the timer based on input parameters
    // ...
}

// Handling expiration event
void time::expiredTime(uint8_t output_device, ...) {
    // Handle events when time runs out
}

// Retrieving current time values
uint8_t time::getHours() {
    return hours;
}

uint8_t time::getMinutes() {
    return minutes;
}

uint8_t time::getSeconds() {
    return seconds;
}