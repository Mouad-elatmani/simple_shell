#include "shel.h"
/**
 * convert_to_string - Function to convert an integer to a string.
 * @num: The integer to be converted.
 * Return: The string representation of the integer.
 */
char *convert_to_string(int num)
{
	unsigned int digit, count;
	int length = 0, i = 0;
	char *result;

	digit = num;
	count = 1;
	while (digit > 9)
	{
		digit /= 10;
		count *= 10;
		length++;
	}
	length++;
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	for (; count >= 1; count /= 10)
		result[i++] = ((num / count) % 10) + '0';
	result[length] = '\0';

	return (result);
}
/**
 * print_exit_error - Function to print exit error.
 * @program_name: The name of the program.
 * @command_count_str: String representation of command count.
 * @input_line: The input line.
 * Return: None.
 */
void print_exit_error(char *program_name, char *command_count_str,
		char *input_line)
{
	char *token;

	_string_tokenize(input_line, TOK_DELIM);
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, command_count_str, _strlen(command_count_str));
	write(2, ": ", 2);
	write(2, input_line, _strlen(input_line));
	write(2, ": ", 2);
	write(2, "Illegal number", sizeof("Illegal number:") - 1);
	write(2, ": ", 2);
	token = _string_tokenize(NULL, TOK_DELIM);
	write(2, token, _strlen(token));
	write(2, "\n", 1);
}
