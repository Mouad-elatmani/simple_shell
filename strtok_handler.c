#include "shel.h"
/*pj1*/

/**
 * is_delim - function checks if "c" is one of the delimiters specified
 * @c: the character we gonna check
 * @delim: the string which contain delimiter characters
 * Return: 0 or 1
 */
int is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * strtok_handler - a function that split a string into tokens
 * @str: the string we wanna split
 * @delim: contain the provided delimiters
 * Return: returns a token which points to the beginning of "str"
 */

char *strtok_handler(char *str, const char *delim)
{
	static char *current_position;
	char *token_start;

	if (str != NULL)
		current_position = str;

	if (!current_position)
		return (NULL);

/* Skip any initial delimiters */
	while (*current_position && is_delim(*current_position, delim))
		current_position++;

	if (*current_position == '\0')
	{
		current_position = NULL;
		return (NULL);
	}

	token_start = current_position;

	while (*current_position && !is_delim(*current_position, delim))
		current_position++;

	if (*current_position)
	{
		*current_position = '\0';
		current_position++;
	}

	return (token_start);
}
