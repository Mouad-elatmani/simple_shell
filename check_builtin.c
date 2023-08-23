#include "shel.h"
/**
 * check_builtin - Function that checks for built-in commands.
 * @program_name: Program name.
 * @input_line: The line of input.
 * @process_status: Pointer to process status.
 * @command_count: Count of commands.
 * @message: Line message.
 * Return: Index of the built-in command or -1.
 */
int check_builtin(char *program_name, char *input_line, int *process_status,
		int command_count, char *message)
{
	int index, f = 1;
	char *line_copy;
	char *bu_com[] = {"exit", "env", "echo"};

	line_copy = strdup(input_line);
	line_copy = _string_tokenize(line_copy, " ");
	for (index = 0; index < 2; index++)
	{
		if (_strcmp(line_copy, bu_com[index]) == 0)
		{
			f = 0;
			free(line_copy);
			break;
		}
	}
	switch (index)
	{
		case 0:
			cu_exit(input_line, process_status, command_count, program_name, message);
			break;
		case 1:
			print_environment();
			break;
	}
	if (f)
	{
		free(line_copy);
		return (-1);
	}
	else
		return (index);
}

