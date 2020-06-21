#include "command_parser.h"
#include "bit_operation_helper.h"
#include "string_helper.h"

static const struct option
{
    char short_opt;
    char *long_opt;
    int parameter_count;
    f_opt_handler opt_handler;
} option_list[] =
{
        {'x', "xor", 1, xor_module_handler},
        {'r', "rot", 1, rot_module_handler},
        {0, 0, 0, NULL}
};

char* key = NULL;
size_t key_size = 0;
int crypting_type = 0;
optind = 1;

void xor_module_handler (char* new_key)
{
    crypting_type = 1;
    key_size = sizeof(new_key);
    if (NULL == key)
    {
        key = malloc(key_size);
    }
    else
    {
        key = realloc(key, key_size);
    }
}

void rot_module_handler (char* new_key)
{
    crypting_type = 2;
    key_size = sizeof(new_key);
    if (NULL == key)
    {
        key = malloc(key_size);
    }
    else
    {
        key = realloc(key, key_size);
    }
}

int opt_request_arg(char opt, char *optstring)
{
    if (NULL == optstring)
        return -2;

    for (int i = 0; i < my_strlen(optstring); i++)
    {
        if (opt == optstring[i])
        {
            if (optstring[i+1] == ':')
                return 1;
            else
                return 0;
        }
    }
    return -1;
}

int get_opt(int argc, char * const argv[], char * const optstring, char **arg_buff)
{
    static int next_char = 0;

    if (next_char >= sizeof(argv[optind]))
        return  -1;

    if ((0 == my_strcmp("-", argv[optind])) || (0 == my_strcmp("--", argv[optind])))
    {
        optind++;
        return get_opt(argc, argv, optstring, &arg_buff);
    }

    char current_char = argv[optind][next_char];
    if ('-' == current_char)
    {
        next_char++;
    }
    else
    {
        return -1;
    }

    current_char =  argv[optind][next_char];
    next_char++;
    if (next_char >= my_strlen(argv[optind]))
    {
        next_char = 0;
        optind++;
    }

    switch (opt_request_arg(current_char, optstring))
    {
        case 1:
            *arg_buff = &argv[optind][next_char];
            break;
        case -1:
            printf("char not in option list.\n");
            break;
        case -2:
            printf("option list is empty.\n");
            break;
        default:
            break;
    }

    return current_char;
}