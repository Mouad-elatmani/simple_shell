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

/**
 * str_cpy - function that Copies the string "src"
 * @src: the source
 * @dest: the destination
 * Retun: the destination
 */

char *str_cpy(char *src, char *dest)
{
	char *f_dest = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (f_dest);
}
