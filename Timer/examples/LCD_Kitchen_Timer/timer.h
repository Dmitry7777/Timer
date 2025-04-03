#ifndef TIMER_H
#define TIMER_H

#include <stdint.h> // For data types like uint8_t, uint16_t, etc.
#include <stdarg.h> // For variable argument lists (...)

class time {
public:
    // Constructors
    time(); // Default constructor
    time(uint8_t hours, uint8_t minutes, uint8_t seconds);

    // Add an output device with a callback function
    void addOutputDevice(uint8_t deviceType, void (*deviceCallback)(uint8_t));

    // Setting time formats
    void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
    void setHours(uint8_t hours);
    void setMinutes(uint8_t minutes);
    void setSeconds(uint8_t seconds);

    // Increasing/decreasing time
    void increaseTime(uint8_t button);
    void decreaseTime(uint8_t button);

    // Starting/stopping the timer
    void startTimer(uint8_t output_device, ...);
    void stopTimer(uint8_t output_device, ...);

    // Delaying the timer
    void delayTimer(uint8_t hrs, uint8_t mins, uint8_t secs, uint8_t output_device, ...);

    // Event triggered when time expires
    void expiredTime(uint8_t output_device, ...);

    // Getting current time values
    uint8_t getHours();
    uint8_t getMinutes();
    uint8_t getSeconds();

private:
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

    bool running; // Indicates whether the timer is running

    struct Device {
        uint8_t deviceType;
        void (*callback)(uint8_t);
    };

    static const int MAX_DEVICES = 10;
    Device devices[MAX_DEVICES];
    int numDevices;
};

#endif // TIMER_H