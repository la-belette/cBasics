#include "common.h"
#include "string_helper_tests.h"
#include "matrix_helper_tests.h"
#include "memory_manager_tests.h"
#include "calendar_helper_tests.h"
#include "array_helper_tests.h"
#include "bit_operations_tests.h"
#include "list_helper_tests.h"
#include "thread.h"
#include "crypting_interface.h"
#include "bit_operation_helper.h"
#include "string_helper.h"

//#define STRING_TEST
//#define MATRIX_TEST
//#define MEMORY_MGT_TEST
//#define CALENDAR_TEST
//#define ARRAY_TEST
//#define BIT_TEST
//#define LIST_TEST
//#define THREAD_TEST

int main(int argc, char* argv[])
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

    if (argc >= 5)
    {
        s_crypto_interface crypto_itf_rot;
        crypto_itf_rot.encrypt = my_rol_crypt;
        crypto_itf_rot.decrypt = my_ror_crypt;

        s_crypto_interface crypto_itf_xor;
        crypto_itf_xor.encrypt = my_xor_crypt;
        crypto_itf_xor.decrypt = my_xor_crypt;

        s_crypto_interface* generic_crypto_itf = malloc(sizeof(s_crypto_interface));

        char *crypting_type = malloc(30);
        char *message = malloc(30);
        char *key = malloc(30);
        int key_length;

        crypting_type = my_strcpy(crypting_type, argv[1]);
        key = my_strcpy(key, argv[2]);
        key_length = my_strlen(argv[2]);

        if (0 == my_strcmp(crypting_type, "x"))
        {
            generic_crypto_itf = &crypto_itf_xor;
        }
        else if (0 == my_strcmp(crypting_type, "r") )
        {
            generic_crypto_itf = &crypto_itf_rot;
        }
        else
        {
            printf("Unidentified crypting type.\n");
            return -1;
        }

        for (int arg = 3; arg < argc; arg++)
        {
            message = my_strcpy(message, argv[arg]);
            printf("Original message: %s.\n", message);
            generic_crypto_itf->encrypt(message, my_strlen(message), key, key_length);
            printf("Encrypted message: ");
            char_array_print(message,  my_strlen(message));
        }

        free(crypting_type);
        free(message);
        free(key);

    }
    return (0);
}
