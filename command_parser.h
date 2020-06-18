#ifndef CBASICS_COMMAND_PARSER_H
#define CBASICS_COMMAND_PARSER_H

extern char *opt_arg;
int optind = 1;

typedef void (*f_opt_handler)(char *parameter);
void xor_module_handler (char* new_key);
void rot_module_handler (char* key);
int get_opt(int argc, char * const argv[], char * const optstring);

#endif //CBASICS_COMMAND_PARSER_H
