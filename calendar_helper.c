#include "calendar_helper.h"

#include <string.h>

char* getWeekDay (char* currentDay, int delay)
{
    static char* weekDays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int numberOfWeekDays = 7;

    for (int i = 0; i < numberOfWeekDays; i++)
    {
        if (0 == strcmp(currentDay, weekDays[i]))
        {
            return  weekDays[(delay + i) % numberOfWeekDays];
        }
    }
    return "Not a correct day";
}
