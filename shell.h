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



/* handle_strings.c and handle_strings2.c functions */

int str_len(const char *s);
int str_cmp(char *str1, char *str2);
char *str_cat(char *src, char *dest);
char *str_dup(char *str);
char *str_cpy(char *src, char *dest);

/* strtok_handler.c functions */

int is_delim(char c, const char *delim);
char *strtok_handler(char *str, const char *delim);

#endif
