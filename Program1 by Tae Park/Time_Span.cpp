#include "Time_Span.h"
#include <cmath>

// Constructors
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}

// Seconds Constructors
TimeSpan::TimeSpan(double seconds) 
{
    hours_ = 0;
    minutes_ = 0;
    seconds_ = round(seconds);
    fixTime();
}

// Minutes Seconds Constructors
TimeSpan::TimeSpan(double minutes, double seconds) 
{
    hours_ = 0;
    minutes_ = round(minutes);
    seconds_ = round(seconds);
    fixTime();
}

// Hours Minutes Seconds Constructors
TimeSpan::TimeSpan(double hours, double minutes, double seconds) 
{
    hours_ = round(hours);
    minutes_ = round(minutes);
    seconds_ = round(seconds);
    fixTime();
}

// method that converts time
void TimeSpan::fixTime() {
   
    while (seconds_ >= 60 || seconds_ <= -60) 
    {
        if (seconds_ >= 60) {
            seconds_ -= 60;
            minutes_++;
        } else {
            seconds_ += 60;
            minutes_--;
        }
    }


    while (minutes_ >= 60 || minutes_ <= -60) 
    {
        if (minutes_ >= 60) {
            minutes_ -= 60;
            hours_++;
        } else {
            minutes_ += 60;
            hours_--;
        }
    }

    // Ensure seconds and minutes have the same sign as hours
    if (hours_ < 0 && minutes_ > 0) 
    {
        hours_++;
        minutes_ -= 60;
    }
    if (hours_ < 0 && seconds_ > 0) 
    {
        minutes_++;
        seconds_ -= 60;
    }
    if (minutes_ < 0 && seconds_ > 0) 
    {
        minutes_++;
        seconds_ -= 60;
    }
}

//getters-setters
int TimeSpan::Hours() const 
{
    return hours_;
}

int TimeSpan::Minutes() const 
{
    return minutes_;
}

int TimeSpan::Seconds() const 
{
    return seconds_;
}

void TimeSpan::Time(double hours, double minutes, double seconds) 
{
    hours_ = round(hours);
    minutes_ = round(minutes);
    seconds_ = round(seconds);
    fixTime();
}


// checking if
bool TimeSpan::operator==(const TimeSpan& other) const 
{
    return (hours_ == other.hours_ && minutes_ == other.minutes_ && seconds_ == other.seconds_);
}

bool TimeSpan::operator!=(const TimeSpan& other) const 
{
    return !(*this == other);
}

// Add the += operator
TimeSpan& TimeSpan::operator+=(const TimeSpan& other) 
{
    hours_ += other.hours_;
    minutes_ += other.minutes_;
    seconds_ += other.seconds_;
    fixTime();
    return *this;
}

