#ifndef _SHELL_H
#define _SHELL_H
#define TOK_DELIM " \t\r\n\a\""
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define BUFSIZE 1024
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
extern char **environ;

/*nrrors*/
void command_error(char *program_name, char *command_count_str,
		char *input_line);
void _permission_error(char *program_name, char *command_count_str,
		char *input_line);
void print_cu_err(char *program_name, int command_count, int status,
		char *input_line);
void print_exit_error(char *program_name, char *command_count_str,
		char *input_line);
/* environnemnt*/
void print_environment(void);
char *_get_envi_value(char *name);


/*exit*/
int cu_exit(char *line, int *status, int count, char *prog_name,
		char *message);

/*strings*/
char *_strdup(char *str);
void _strcat(char *str1, const char *str2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *convert_to_string(int num);

/* more functions*/
ssize_t cu_getline(char **lineptr, size_t *n, FILE *stream);
char *_string_tokenize(char *str, const char *delimiters);
/*execution commande */
char *find_executable(char *line);
void _execute_not_found(char *command_path, char **cmd_argv,
		char *environment[], int *status);
char **generate_arguments(char *line);
int execute_command(char *command, char **arguments, char *environment[],
		int *status);
char *new_line_handler(char *line);
int check_builtin(char *program_name, char *input_line, int *process_status,
		int command_count, char *message);
/* modes*/
void run_non_interactive_mode(char **argv);
void run_interactive_shell(char **arguments);


void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
#endif
