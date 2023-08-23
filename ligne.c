#include "shel.h"
/**
 * cu_getline - Function for reading a line from a stream.
 * @lineptr: Pointer to a string.
 * @n: Size of the buffer.
 * @stream: Stream.
 * Return: Number of characters read.
 */
ssize_t cu_getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
