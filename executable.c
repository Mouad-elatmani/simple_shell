#include "shel.h"
/**
 * find_executable - Function checks if a command is executable or not
 * @line: The input line from getline function
 * Return: The executable command or NULL if not found
 */
char *find_executable(char *line)
{
	char *token, *line_copy, *path_copy, *path, *str;
	int command_len = 0, tok_len = 0;

	path = _get_envi_value("PATH");
	path_copy = _strdup(path);
	line_copy = _strdup(line);
	_string_tokenize(line_copy, TOK_DELIM);

	if ((access(line_copy, F_OK) == 0) && (line_copy[0] == '/' ||
				line_copy[1] == '/' || line_copy[2] == '/'))
	{
		free(path_copy);
		return (line_copy);
	}
	command_len = (int)_strlen(line_copy);
	token = _string_tokenize(path_copy, ":");
	tok_len = (int)_strlen(token);
	while (token)
	{
		str = malloc(command_len + tok_len + 2);
		_strcpy(str, token);
		_strcat(str, "/");
		_strcat(str, line_copy);
		if (access(str, F_OK) == 0)
		{
			free(line_copy);
			free(path_copy);
			return (str);
		}
		free(str);
		token = _string_tokenize(NULL, ":");
		if (!token)
		{
			free(line_copy);
			free(path_copy);
			break;
		}
		tok_len = (int)_strlen(token);
	}
	return (NULL);
}
