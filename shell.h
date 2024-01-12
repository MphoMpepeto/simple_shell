#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define INPUT_SIZE 1024
#define PEAK_ARGS 1024

extern char **environ;

void yenza_command(char **argv, char *getline_num);
int shell_setenv(const char *name, const char *value);
int shell_unsetenv(const char *name);
char *my_getline(void);
char *str_tok(char *strng, const char *delimeter);
char *non_interactive_reader(void);
int shell_cd(const char *directory);
void check_eof(char *buff);
void print_error(void);
void exec(char *args[], char *getline_num);
char *get_env(char *env_var);
void change_dir(char *cmd_args[], char *currt_wrk_dir);
void cmd_seperator(char *get_line_val, char *currt_wrk_dir, char *user_prompt);
int _printf(const char *format, ...);
int _putchar(char c);
int error_printer(char ch);
int _strlen(char *str);
void output_int(int num);
int _err_printf(FILE *strm, const char *formt, ...);
int num_length(int num);
int cstm_strncmp(char *str1, char *str2, int num);


#endif
