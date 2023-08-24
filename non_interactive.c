#include "shel.h"
/**
 * run_non_interactive_mode - Function to runprogram in non-interactive mode
 * @argv: Argument vector
 * Return: void
 */
void run_non_interactive_mode(char **argv)
{
	    char *line = NULL, *command, *line_copy;
	    char **cmd_arguments = {NULL}, *environment[] = {NULL};
	    size_t len = 0;
	    ssize_t read;
	    int status = 0, count = 0, i;

	while (1)
	{
		count++;
		read = cu_getline(&line, &len, stdin);
		if (read == -1)
			break;
		line_copy = new_line_handler(line);
		command = find_executable(line_copy);
		if (_strcmp(line_copy, "\n") == 0 || line_copy[0] == '#')
			continue;
		else if (check_builtin(argv[0], line_copy, &status, count, line) != -1)
		{
			free(command);
			continue;
		}
		else if (command != NULL)
		{
			cmd_arguments = generate_arguments(line_copy);
			i = execute_command(command, cmd_arguments, environment, &status);
			if (i == 0)
				print_cu_error(argv[0], count, status, line_copy);
		}
		else if (command == NULL)
		{
			_execute_not_found(line_copy, cmd_arguments, environment, &status);
			print_cu_error(argv[0], count, status, line_copy);
		}
		free(command);
	}
	free(line);
}
