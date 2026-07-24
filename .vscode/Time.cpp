#include "Time.h"


Time::Time()
{
    days = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
}



Time::Time(int d, int h, int m, int s)
{
    days = d;
    hours = h;
    minutes = m;
    seconds = s;
}



Time::Time(int h, int m, int s)
{
    days = 0;
    hours = h;
    minutes = m;
    seconds = s;
}



Time::Time(int h, int m)
{
    days = 0;
    hours = h;
    minutes = m;
    seconds = 0;
}




Time::Time(Time& time)
{
    days = time.days;
    hours = time.hours;
    minutes = time.minutes;
    seconds = time.seconds;
}




int Time::getDays()
{
    return days;
}


int Time::getHours()
{
    return hours;
}


int Time::getMinutes()
{
    return minutes;
}


int Time::getSeconds()
{
    return seconds;
}





void Time::setDays(int d)
{
    days = d;
}


void Time::setHours(int h)
{
    hours = h;
}


void Time::setMinutes(int m)
{
    minutes = m;
}


void Time::setSeconds(int s)
{
    seconds = s;
}





Time& Time::operator=(Time& right)
{

    if(this != &right)
    {
        days = right.days;
        hours = right.hours;
        minutes = right.minutes;
        seconds = right.seconds;
    }


    return *this;
}







Time& Time::operator+(Time& right)
{

    seconds += right.seconds;
    minutes += right.minutes;
    hours += right.hours;
    days += right.days;



    while(seconds >= 60)
    {
        seconds -= 60;
        minutes++;
    }


    while(seconds < 0)
    {
        seconds += 60;
        minutes--;
    }


    while(minutes >= 60)
    {
        minutes -= 60;
        hours++;
    }


    while(minutes < 0)
    {
        minutes += 60;
        hours--;
    }


    while(hours >= 24)
    {
        hours -= 24;
        days++;
    }


    while(hours < 0)
    {
        hours += 24;
        days--;
    }


    return *this;
}







bool Time::operator>(Time& right)
{
    return (int)*this > (int)right;
}



bool Time::operator<(Time& right)
{
    return (int)*this < (int)right;
}



bool Time::operator>=(Time& right)
{
    return (int)*this >= (int)right;
}



bool Time::operator<=(Time& right)
{
    return (int)*this <= (int)right;
}



bool Time::operator==(Time& right)
{
    return (int)*this == (int)right;
}








ostream& operator<<(ostream& stream, Time& right)
{

    stream << right.days << " days, "
           << right.hours << " hours, "
           << right.minutes << " minutes, "
           << right.seconds << " seconds";


    return stream;
}







Time::operator int()
{

    int totalSeconds = 0;


    totalSeconds += days * 86400;

    totalSeconds += hours * 3600;

    totalSeconds += minutes * 60;

    totalSeconds += seconds;


    return totalSeconds;
}