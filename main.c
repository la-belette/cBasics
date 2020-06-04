#include "common.h"
#include "string_helper_tests.h"
#include "matrix_helper_tests.h"
#include "memory_manager_tests.h"
#include "calendar_helper_tests.h"
#include "array_helper_tests.h"
#include "bit_operations_tests.h"
#include "list_helper_tests.h"
#include "thread.h"

//#define STRING_TEST
//#define MATRIX_TEST
//#define MEMORY_MGT_TEST
//#define CALENDAR_TEST
//#define ARRAY_TEST
#define BIT_TEST
#define LIST_TEST
#define THREAD_TEST

int main(void)
{
#ifdef STRING_TEST
    printf("\n*******************************************************\n");
    printf("                     STRING TEST                       \n");
    printf("*******************************************************\n\n");

    if (0 == test_string_helper())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef CALENDAR_TEST
    printf("\n*******************************************************\n");
    printf("                    CALENDAR TEST                      \n");
    printf("*******************************************************\n\n");

    if (0 == test_calendar_helper())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef MATRIX_TEST
    printf("\n*******************************************************\n");
    printf("                     MATRIX TEST                       \n");
    printf("*******************************************************\n\n");

    if (0 == test_matrix_helper())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef MEMORY_MGT_TEST
    printf("\n*******************************************************\n");
    printf("                MEMORY MANAGEMENT TEST                 \n");
    printf("*******************************************************\n\n");

    if (0 == test_memory_management())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef ARRAY_TEST
    printf("\n*******************************************************\n");
    printf("                       ARRAY TEST                      \n");
    printf("*******************************************************\n\n");

    if (0 == test_array())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef BIT_TEST
    printf("\n*******************************************************\n");
    printf("                        BIT TEST                       \n");
    printf("*******************************************************\n\n");

    if (0 == test_bit_operations())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef LIST_TEST
    printf("\n*******************************************************\n");
    printf("                        LIST TEST                      \n");
    printf("*******************************************************\n\n");

    if (0 == test_list_helper())
        printf("success\n");
    else
        printf("fail\n");
#endif

#ifdef THREAD_TEST
    printf("\n*******************************************************\n");
    printf("                      THREAD TEST                      \n");
    printf("*******************************************************\n\n");

    if (0 == threads_handler())
        printf("success\n");
    else
        printf("fail\n");
#endif

    return (0);
}
