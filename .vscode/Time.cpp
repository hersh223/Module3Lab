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

    normalize();
}



Time::Time(int h, int m, int s)
{
    days = 0;
    hours = h;
    minutes = m;
    seconds = s;

    normalize();
}



Time::Time(int h, int m)
{
    days = 0;
    hours = h;
    minutes = m;
    seconds = 0;

    normalize();
}



Time::Time(const Time& time)
{
    days = time.days;
    hours = time.hours;
    minutes = time.minutes;
    seconds = time.seconds;
}



Time::~Time()
{

}



int Time::getDays() const
{
    return days;
}



int Time::getHours() const
{
    return hours;
}



int Time::getMinutes() const
{
    return minutes;
}



int Time::getSeconds() const
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
    normalize();
}



void Time::setMinutes(int m)
{
    minutes = m;
    normalize();
}



void Time::setSeconds(int s)
{
    seconds = s;
    normalize();
}





void Time::normalize()
{

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

}





Time& Time::operator=(const Time& right)
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





Time Time::operator+(const Time& right)
{

    Time result;


    result.days = days + right.days;

    result.hours = hours + right.hours;

    result.minutes = minutes + right.minutes;

    result.seconds = seconds + right.seconds;


    result.normalize();


    return result;

}





Time Time::operator-(const Time& right)
{

    Time result;


    result.days = days - right.days;

    result.hours = hours - right.hours;

    result.minutes = minutes - right.minutes;

    result.seconds = seconds - right.seconds;


    result.normalize();


    return result;

}





bool Time::operator>(const Time& right) const
{
    return totalSeconds() > right.totalSeconds();
}



bool Time::operator<(const Time& right) const
{
    return totalSeconds() < right.totalSeconds();
}



bool Time::operator>=(const Time& right) const
{
    return totalSeconds() >= right.totalSeconds();
}



bool Time::operator<=(const Time& right) const
{
    return totalSeconds() <= right.totalSeconds();
}



bool Time::operator==(const Time& right) const
{
    return totalSeconds() == right.totalSeconds();
}





ostream& operator<<(ostream& stream, const Time& right)
{

    stream << right.days << " days, "
           << right.hours << " hours, "
           << right.minutes << " minutes, "
           << right.seconds << " seconds";


    return stream;

}





int Time::totalSeconds() const
{

    return days * 86400
         + hours * 3600
         + minutes * 60
         + seconds;

}





Time::operator int() const
{

    return days * 86400
         + hours * 3600
         + minutes * 60
         + seconds;

}