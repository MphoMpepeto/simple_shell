#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#define MAX_PATH_SIZE PATH_MAX

void kyere_prompt(void);
void gye_input(void);
void she_prints(const char *printee);
void yenza_command(char *nipa_input);
void check_malloc(char **variable);
void ye_commd(char *nipa_input, char **argv, char *pokemon, char *delimetr);
void free_memory(char **array_of_pokemons, char *copy_nipa, char *nipa_input);
void exit_shell(char *nipa_input);
void print_environ(void);
char *str_concat(char *dest, char *src);
char *str_copy(char *dest, char *src);
void handl_path_commd(char **argv);
extern char **environ;
char *str_chr(char *s, char c);
int str_len(char *s);
int str_cmp(char *s1, char *s2);
char *str_str(char *haystack, char *needle);
void erro_mgs(char *counter, char *argv);
int update_PWD(char *our_path);
void err_printer(char *err_msg);
int change_dir(const char *dirt);
int pwd_update(void);
int cd_main(int argc, char argv[]);
bool is_interact(void);
void exec_output(char **argv);
void free_argv(char **argv);

#endif
