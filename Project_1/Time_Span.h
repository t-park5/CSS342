#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;

class TimeSpan
{
private:
    int hours_;
    int minutes_;
    int seconds_;
    void fixTime(); // Helper function to convert time

public:
    
    // Constructor
    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);

    // Getters-setters
    int Hours() const;
    int Minutes() const;
    int Seconds() const;

    void Time(double hours, double minutes, double seconds);

    // Overloading operators
    TimeSpan operator+(const TimeSpan& other) const
    {
        return TimeSpan(hours_ + other.hours_,  minutes_ + other.minutes_, seconds_ + other.seconds_);
    }

    TimeSpan operator-(const TimeSpan& other) const
    {
        return TimeSpan(hours_ - other.hours_, minutes_ - other.minutes_, seconds_ - other.seconds_);
    }


    TimeSpan& operator+=(const TimeSpan& other);


    TimeSpan operator-() const
    {
        return TimeSpan(-hours_, -minutes_, -seconds_);
    }

    // Comparison
    bool operator==(const TimeSpan& other) const;
    bool operator!=(const TimeSpan& other) const;

    // Stream operators
    friend ostream& operator<<(ostream& os, const TimeSpan& ts)
    {
        os << "Hours: " << ts.hours_ << ", Minutes: " << ts.minutes_ << ", Seconds: " << ts.seconds_;
        return os;
    }

    friend istream& operator>>(istream& is, TimeSpan& ts)
    {
        double h, m, s;
        is >> h >> m >> s;
        ts.Time(h, m, s);
        return is;
    }
};

#endif