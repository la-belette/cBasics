#include "calendar_helper_tests.h"
#include "calendar_helper.h"

int test_get_week_day()
{
    printf("7 days after Monday is: %s\n",getWeekDay("Mon", 7));
    printf("3 days after Wednesday is: %s\n",getWeekDay("Wed", 3));
    printf("0 days after Monday is: %s\n",getWeekDay("Mon", 0));
    printf("21 days after Sunday is: %s\n",getWeekDay("Sun", 7));
    printf("284 days after _ is: %s\n",getWeekDay("", 284));

    return 0;
}

int test_calendar_helper()
{
    int result = 0;
    if (0 != test_get_week_day())
        result = -1;
    return result;
}