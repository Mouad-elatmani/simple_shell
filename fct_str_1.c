#include "shel.h"
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - compare 2 strings.
 * @s1: string to be compared.
 * @s2: string for comparation.
 * Return: Difference.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int result = 0;
	int len1, len2;

	len1 = (int)strlen(s1);
	len2 = (int)strlen(s2);

	if (len1 != len2)
		return (-1);

	for (i = 0; ((s1[i] != '\0') && (s2[i] != '\0')); i++)
	{
		result = (s1[i] - s2[i]);
		if (result != 0)
		{
			return (result);
		}
	}
	return (0);
}
/**
*_strdup - returns a pointer to a newly allocated space in memory
*@str: string to be duplicated
*Return: pointer to a new string which is a duplicate of the string str
*/
char *_strdup(char *str)
{
	char *new_str;
	unsigned int i;
	unsigned int size;

	if (str == NULL)
		return (NULL);

	size = _strlen(str);

	new_str = (char *)malloc(size + 1);

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= size; i++)
		new_str[i] = str[i];

	return (new_str);
}
/**
 * _strcat - Function that copy
 * @str1: first string
 * @str2: Second String
*/
void _strcat(char *str1, const char *str2)
{
	size_t len1 = strlen(str1);
	size_t i = 0;

	while (str2[i])
	{
		str1[len1 + i] = str2[i];
		i++;
	}

	str1[len1 + i] = '\0';
}
