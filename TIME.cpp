#include"TIME.h"

int Time::getHour() const{
    return hour;
}
int Time::getMinute() const{
    return minute;
}
void Time::setHour(int newHour){
    hour = newHour;
}
void Time::setMinute(int newMinute){
    minute = newMinute;
}
