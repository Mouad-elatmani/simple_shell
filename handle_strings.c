#include "shell.h"

/**
 * str_len - function that calcule the lenght of a string.
 * @s: the string we gonna use
 * Return: the length of string
 */
int str_len(const char *s)
{
	int n = 0;

	while (*(s + n))
		n++;
	return (n);
}

/**
 * str_cmp - a function that compares 2 strings
 * @str1: the first string
 * @str2: the second string
 * Return: 1 or 0 or -1
 */

int str_cmp(char *str1, char *str2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 > *s2)
		return (1);
	if (*s1 < *s2)
		return (-1);
	return (0);
}

/**
 * str_cat - a function that concatenate two strings
 * @src: the source
 * @dest: the destination
 * Return: returns destination
 */

char *str_cat(char *src, char *dest)
{
	char *f_dest = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (f_dest);
}
