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



/* handle_strings.c functions */

int _strlen(const char *s);

/* strtok_handler.c functions */

int is_delim(char c, const char *delim);
char *strtok_handler(char *str, const char *delim);

#endif
