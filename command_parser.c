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
        return -1;
    for (int i = 0; i < sizeof(optstring); i ++)
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

int get_opt(int argc, char * const argv[], char * const optstring)
{
    static int nextchar = 0;
    int current_char = 0;

    if (nextchar >= argc)
        return  -1;

    if ((0 == my_strcmp("-", argv[optind])) || (0 == my_strcmp("--", argv[optind])))
    {
        optind++;
        return get_opt(argc, argv, optstring);
    }

    if (0 == nextchar)
    {
        nextchar++;
    }

    if (nextchar < sizeof(argv[optind]))
    {
        current_char =  argv[optind][nextchar];
        nextchar++;
        if (nextchar >= sizeof(argv[optind]))
        {
            nextchar = 0;
            optind++;
        }
    }
/*
    if (1 == opt_request_arg(current_char, optstring))
    {
        optind++;

        if (NULL == opt_arg)
            opt_arg = malloc(sizeof(argv[optind]));
        else
            opt_arg = realloc(opt_arg, sizeof(argv[optind]));

        opt_arg = my_strcpy(opt_arg, argv[optind]);

        optind++;
    }
    */
    return current_char;
}