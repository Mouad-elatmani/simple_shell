#include "shel.h"
/**
 * command_error - Function to print not found error.
 * @program_name: The name of the program.
 * @command_count_str: String representation of command count.
 * @input_line: The input line.
 * Return: None.
 */
void command_error(char *program_name, char *command_count_str,
		char *input_line)
{
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, command_count_str, _strlen(command_count_str));
	write(2, ": ", 2);
	write(2, input_line, _strlen(input_line));
	write(2, ": ", 2);
	write(2, "not found", sizeof("not found") - 1);
	write(2, "\n", 1);
}
/**
 * _permission_error - Function to print permission error.
 * @program_name: The name of the program.
 * @command_count_str: String representation of command count.
 * @input_line: The input line.
 * Return: None.
 */
void _permission_error(char *program_name, char *command_count_str,
		char *input_line)
{
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, command_count_str, _strlen(command_count_str));
	write(2, ": ", 2);
	write(2, input_line, _strlen(input_line));
	write(2, ": ", 2);
	write(2, "Permission denied", sizeof("Permission denied") - 1);
	write(2, "\n", 1);
}
/**
 * print_cu_err - Function to print custom error messages.
 * @program_name: The name of the program.
 * @command_count: Count of commands.
 * @status: Process status.
 * @input_line: The input line.
 * Return: None.
 */
void print_cu_err(char *program_name, int command_count, int status,
		char *input_line)
{
	char *command_count_str;

	command_count_str = convert_to_string(command_count);
	if (status == 126)
		_permission_error(program_name, command_count_str, input_line);
	if (status == 127)
		command_error(program_name, command_count_str, input_line);
	if (status == 2 && (strncmp(input_line, "exit", 4) == 0))
		print_exit_error(program_name, command_count_str, input_line);
	free(command_count_str);
}
