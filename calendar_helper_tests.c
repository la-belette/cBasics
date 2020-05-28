#include "calendar_helper_tests.h"
#include "calendar_helper.h"
#include <string.h>

int test_get_week_day()
{
    int err = 0;

    static char* weekDays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int delay_input = 7;
    int day_input_index = 0;
    int expected_result_index = (day_input_index + delay_input)%7;
    char* result = getWeekDay(weekDays[day_input_index], delay_input);
    if (0 != strcmp(result, weekDays[expected_result_index]))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result, weekDays[expected_result_index]);
        err = -1;
    }

    delay_input = 3;
    day_input_index = 2;
    expected_result_index = (day_input_index + delay_input)%7;
    char* result2 = getWeekDay(weekDays[day_input_index], delay_input);
    if (0 != strcmp(result2, weekDays[expected_result_index]))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result2, weekDays[expected_result_index]);
        err = -1;
    }

    delay_input = 0;
    day_input_index = 0;
    expected_result_index = (day_input_index + delay_input)%7;
    char* result3 = getWeekDay(weekDays[day_input_index], delay_input);
    if (0 != strcmp(result3, weekDays[expected_result_index]))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result3, weekDays[expected_result_index]);
        err = -1;
    }

    delay_input = 7;
    day_input_index = 6;
    expected_result_index = (day_input_index + delay_input)%7;
    char* result4 = getWeekDay(weekDays[day_input_index], delay_input);
    if (0 != strcmp(result4, weekDays[expected_result_index]))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result4, weekDays[expected_result_index]);
        err = -1;
    }

    delay_input = 284;
    day_input_index = 6;
    expected_result_index = (day_input_index + delay_input)%7;
    char* result5 = getWeekDay(weekDays[day_input_index], delay_input);
    if (0 != strcmp(result5, weekDays[expected_result_index]))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result5, weekDays[expected_result_index]);
        err = -1;
    }

    day_input_index = 1;
    char *expected_result = "Not a correct day";
    char* result6 = getWeekDay("", delay_input);
    if (0 != strcmp(result6, expected_result))
    {
        printf("fail in %d: %d days after %s is: %s instead of %s\n", __func__, delay_input, weekDays[day_input_index], result6, expected_result);
        err = -1;
    }

    return err;
}

int test_calendar_helper()
{
    int err = 0;
    err += test_get_week_day();
    return err;
}