#ifndef TIMER_H
#define TIMER_H

#include <stdint.h> // For data types like uint8_t, uint16_t, etc.

class time {
public:
    // Constructors
    time(); // Default constructor
    time(uint8_t hours, uint8_t minutes, uint8_t seconds);

    // Setting time formats
    void setTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
    void setHours(uint8_t hours);
    void setMinutes(uint8_t minutes);
    void setSeconds(uint8_t seconds);

    // Increasing/decreasing time
    void increaseTime(uint8_t button);
    void decreaseTime(uint8_t button);

    // Starting/stoping the timer
    void startTimer();
    void stopTimer();

    // Delaying the timer
    void delayTimer(uint8_t hours, uint8_t minutes, uint8_t seconds);

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
};

#endif // TIMER_H