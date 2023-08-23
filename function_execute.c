#include "shel.h"
/**
 * generate_arguments - Function to generate argument vector
 * @line: The input line from getline function
 * Return: Array of strings (argument vector)
 */
char **generate_arguments(char *line)
{
	char **arguments, *arg_idx;
	int i = 0;

	arguments = malloc(sizeof(char *) * (_strlen(line) + 1));
	if (!arguments)
		perror("malloc");
	arg_idx = _string_tokenize(line, TOK_DELIM);
	while (arg_idx)
	{
		if (arg_idx[0] == '#')
			break;
		arguments[i] = arg_idx;
		arg_idx = _string_tokenize(NULL, TOK_DELIM);
		i++;
	}
	arguments[i] = NULL;
	return (arguments);
}
/**
 * execute_command - Function to execute a command
 * @command: The command to be executed
 * @arguments: All the arguments after the command
 * @environment: All environment variables
 * @status: Pointer to the process status
 * Return: 0 on success
 */
int execute_command(char *command, char **arguments, char *environment[],
		int *status)
{
	int exit_code;
	int child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror("ERROR IN FORK");
	if (child_pid == 0)
	{
		exit_code = execve(command, arguments, environment);
		if (exit_code == -1)
			exit(126);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		*status = WEXITSTATUS(*status);
	}
	free(arguments);
	return (0);
}

