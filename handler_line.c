#include "shel.h"
/**
 * new_line_handler - Function handles the input line from user
 * @line: The input line from getline function
 * Return: The modified string without leading spaces and new line (\n)
 */
char *new_line_handler(char *line)
{
	int length, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	length = _strlen(line);
	if (length == 1 && line[0] == '\n')
		return (line);
	if (line[length - 1] == '\n')
		line[length - 1] = '\0';
	return (line);
}
