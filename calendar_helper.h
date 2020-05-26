#ifndef CBASICS_CALENDAR_HELPER_H
#define CBASICS_CALENDAR_HELPER_H

#include "common.h"

/*
 * getWeekDay gives a 3 letters abbreviation of the day of the week
 * in delay days from currentDay.
 * @param currentDay : the reference week day from following
 * Mon, Tue, Wed, Thu, Fri, Sat, Sun.
 * @param delay : the target number of days after the reference
 * @return a 3 letter abbreviation of the targetted day of week
 */
char* getWeekDay (char* currentDay, int delay);

#endif //CBASICS_CALENDAR_HELPER_H
