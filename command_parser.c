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

int str_split(const char *target, const char seperator, char **res)
{
    if ((NULL == target) || (NULL == res))
        return -1;
    int separator_nb = 0;
    int target_i = 0;
    int res_i = 0;
    while (target[target_i] != '\0')
    {
        if (target[target_i] == seperator)
        {

            res[separator_nb][res_i] = '\0';
            separator_nb++;
            res_i = 0;
        }
        else
        {
            res[separator_nb][res_i] = target[target_i];
            res_i++;
        }
        target_i++;
    }
    return separator_nb;
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

    char current_char;
    if(start_with(argv[optind], "--", 2))
    {
        size_t options = sizeof(option_list) / sizeof(struct option);

        char ** cmd_split = malloc(2 * sizeof(char*));
        cmd_split[0] = malloc(30* sizeof(char));
        cmd_split[1] = malloc(30* sizeof(char));
        int seperator_nb;

        seperator_nb = str_split(argv[optind], '=', cmd_split);
        if (seperator_nb != 1)
        {
            printf("error: found %d '=' in command.\n", seperator_nb);
        }
        else
        {
            int i = 0;
            while ((0 != my_strcmp(cmd_split[0]+2, option_list[i].long_opt)) && i < options)
            {
                i++;
            }

            if (i < options)
            {
                current_char = option_list[i].short_opt;
            }

            switch (opt_request_arg(current_char, optstring))
            {
                case 1:
                        *arg_buff = cmd_split[1];
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
        }

        free(cmd_split[0]);
        free(cmd_split[1]);
        free(cmd_split);
    }
    else
    {
        current_char = argv[optind][next_char];
        if ('-' == current_char) {
            next_char++;
        } else {
            return -1;
        }

        current_char = argv[optind][next_char];
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
    }

    return current_char;
}