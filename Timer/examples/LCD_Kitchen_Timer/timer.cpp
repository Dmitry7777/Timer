#include "timer.h"

// Default constructor sets time to 00:00:00
time::time() : hours(0), minutes(0), seconds(0), running(false), numDevices(0) {}

// Constructor with parameters
time::time(uint8_t hrs, uint8_t mins, uint8_t secs) : hours(hrs), minutes(mins), seconds(secs), running(false), numDevices(0) {}

// Register an output device with a callback function
void time::addOutputDevice(uint8_t deviceType, void (*deviceCallback)(uint8_t)) {
    if (numDevices < MAX_DEVICES) {
        devices[numDevices].deviceType = deviceType;
        devices[numDevices].callback = deviceCallback;
        numDevices++;
    }
}

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
            break; // Added missing break
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

// Starting the timer with optional output devices
void time::startTimer(uint8_t output_device, ...) {
    va_list args;
    va_start(args, output_device);

    running = true;

    // Activate output devices passed as arguments
    for (int i = 0; i < numDevices; i++) {
        if (devices[i].deviceType == output_device) {
            devices[i].callback(output_device);
        }
    }

    va_end(args);
}

// Stopping the timer with optional output devices
void time::stopTimer(uint8_t output_device, ...) {
    va_list args;
    va_start(args, output_device);

    running = false;

    // Deactivate output devices passed as arguments
    for (int i = 0; i < numDevices; i++) {
        if (devices[i].deviceType == output_device) {
            devices[i].callback(output_device);
        }
    }

    va_end(args);
}

// Delaying the timer with optional output devices
void time::delayTimer(uint8_t hrs, uint8_t mins, uint8_t secs, uint8_t output_device, ...) {
    va_list args;
    va_start(args, output_device);

    // Logic for delaying the timer based on input parameters
    // ...

    // Notify output devices passed as arguments
    for (int i = 0; i < numDevices; i++) {
        if (devices[i].deviceType == output_device) {
            devices[i].callback(output_device);
        }
    }

    va_end(args);
}

// Handling expiration event with optional output devices
void time::expiredTime(uint8_t output_device, ...) {
    va_list args;
    va_start(args, output_device);

    // Handle events when time runs out
    // ...

    // Notify output devices passed as arguments
    for (int i = 0; i < numDevices; i++) {
        if (devices[i].deviceType == output_device) {
            devices[i].callback(output_device);
        }
    }

    va_end(args);
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