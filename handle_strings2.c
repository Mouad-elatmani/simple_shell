#include "shell.h"

/**
 * str_dup - a function that duplicates a string
 * @str: the string we gonna use
 * Return: the duplicated string
 */

char *str_dup(char *str)
{
	int size, i;
	char *dupStr;

	if (str == NULL)
		return (NULL);

	size = str_len(str);
	dupStr = malloc(sizeof(char) * (size + 1));

	if (!dupStr)
		return (NULL);
	for (int i = 0; i <= size; i++)
		dup[i] = s[i];
	return (dupStr);
}
