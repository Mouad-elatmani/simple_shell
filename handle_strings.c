#include "shell.h"

/**
 * _strlen - function that calcule the lenght of a string.
 * @s: the string we gonna use
 * Return: the length of string
 */
int _strlen(const char *s)
{
	int n = 0;

	while (*(s + n))
		n++;
	return (n);
}
