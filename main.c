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
#include "command_parser.h"

//#define STRING_TEST
//#define MATRIX_TEST
//#define MEMORY_MGT_TEST
//#define CALENDAR_TEST
//#define ARRAY_TEST
//#define BIT_TEST
//#define LIST_TEST
//#define THREAD_TEST
#define CRYPTING_TEST

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

#ifdef CRYPTING_TEST
    if (argc >= 3)
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
        char *arg_buff = malloc(30);

        int opt;
        if ((opt = get_opt(argc, argv, "x:r:", &arg_buff)) != -1)
        {
            switch (opt)
            {
                case 'x':
                    generic_crypto_itf = &crypto_itf_xor;
                    break;
                case 'r':
                    generic_crypto_itf = &crypto_itf_rot;
                    break;
                default:
                    printf("option character undefined.\n");
                    return -1;
            }

            optind = 3;
            while (optind < argc)
            {
                message = my_strcpy(message, argv[optind]);
                printf("Original message: %s.\n", message);
                int key_len = my_strlen(arg_buff);
                int data_len = my_strlen(message);
                generic_crypto_itf->encrypt(message, data_len, arg_buff, key_len);
                printf("Encrypted message: ");
                char_array_print(message, data_len);
                optind++;
            }
        }

        free(crypting_type);
        free(message);
        free(generic_crypto_itf);
        free(arg_buff);
    }
#endif
    return (0);
}
