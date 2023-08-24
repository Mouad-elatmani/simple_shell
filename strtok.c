#include "shel.h"

/**
 * _string_tokenize - Function for string .
 * @str: String to tokenize.
 * @delimiters: Delimiters for tokenization.
 * Return: Tokenized character.
 */
char *_string_tokenize(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}
