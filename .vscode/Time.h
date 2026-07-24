#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;


class Time
{

private:

    int days;
    int hours;
    int minutes;
    int seconds;


    void normalize();

    int totalSeconds() const;

public:

    Time();

    Time(int days, int hours, int minutes, int seconds);

    Time(int hours, int minutes, int seconds);

    Time(int hours, int minutes);

    Time(const Time& time);

    ~Time();


    int getDays() const;

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;


    void setDays(int days);

    void setHours(int hours);

    void setMinutes(int minutes);

    void setSeconds(int seconds);



    Time& operator=(const Time& right);


    Time operator+(const Time& right);

    Time operator-(const Time& right);



    bool operator>(const Time& right) const;

    bool operator<(const Time& right) const;

    bool operator>=(const Time& right) const;

    bool operator<=(const Time& right) const;

    bool operator==(const Time& right) const;



    friend ostream& operator<<(ostream& stream,
                               const Time& right);



    operator int() const;

};


#endif