#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/* STRUCTS */
/*______________________________________*/

/**
 * struct data - struct that contains the data
 * @env: environment var
 * @status: the last status of shell
 * @arg_s: the tokens of command
 * @arg_v: vector of argument
 * @count: the count of lines
 */

typedef struct {
	char **env;
	int status;
	char **arg_s;
	char **arg_v;
	int count;
} data;


/*_____________________________________*/

/*env command*/
void print_environment(void);
extern char **cu_environ;
char  *_get_envi_value(char *name);

/* handle_strings.c and handle_strings2.c functions */

int str_len(const char *s);
int str_cmp(char *str1, char *str2);
char *str_cat(char *src, char *dest);
char *str_dup(char *str);
char *str_cpy(char *src, char *dest);
char *str_ncat(char *src, char *dest, int n);
char *str_chr(char *str, char ch);

/* strtok_handler.c functions */

int is_delim(char c, const char *delim);
char *strtok_handler(char *str, const char *delim);

/* handle_env1.c functions */

/*int compare_envs_name(char *name_env, char *name);*/
char *getenv_handler(char *name, char **env_x);
int env_x(data *Data);
/* handle_errors1.c functions */

char *handle_exit_err(data *Data);
char *handle_path126_err(data *Data);
char *handle_env_err(data *Data);

/* errors_handler functions */

int error_handler(data *Data, int val);;


#endif
