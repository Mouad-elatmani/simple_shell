#include "shel.h"


/**
 * bring_line - assigns the line var for get_line
 * @lineptr: Buffer that stores the input str
 * @n: size of line
 * @buffer: str that is being called to line
 * @j: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
    size_t new_size;

    if (*lineptr == NULL)
    {
        new_size = (j > BUFSIZE) ? j : BUFSIZE;
        *n = new_size;
        *lineptr = buffer;
    }
    else if (*n < j)
    {
        new_size = (j > BUFSIZE) ? j : BUFSIZE;
        *n = new_size;
        *lineptr = buffer;
    }
    else
    {
        _strcpy(*lineptr, buffer);
        free(buffer);
    }
}

/**
 * custom_getline - Read input from stream
 * @lineptr: Buffer that stores the input
 * @n: Size of lineptr
 * @stream: Stream to read from
 * Return: The number of bytes
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    int i;
    static ssize_t input;
    ssize_t retval;
    char *buffer;
    char t = 'z';

    if (input == 0)
        fflush(stream);
    else
        return (-1);
    input = 0;

    buffer = malloc(sizeof(char) * BUFSIZE);
    if (buffer == NULL)
        return (-1);

    while (t != '\n')
    {
        i = read(STDIN_FILENO, &t, 1);
        if (i == -1 || (i == 0 && input == 0))
        {
            free(buffer);
            return (-1);
        }
        if (i == 0 && input != 0)
        {
            input++;
            break;
        }
        if (input >= BUFSIZE)
            buffer = custom_realloc(buffer, input, input + 1);
        buffer[input] = t;
        input++;
    }

    buffer[input] = '\0';
    bring_line(lineptr, n, buffer, input);
    retval = input;
    if (i != 0)
        input = 0;

    return (retval);
}
/**
 * custom_realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails, returns NULL.
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *newptr;

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr);

    newptr = malloc(new_size);
    if (newptr == NULL)
        return (NULL);

    if (new_size < old_size)
        memcpy(newptr, ptr, new_size);
    else
        memcpy(newptr, ptr, old_size);

    free(ptr);
    return (newptr);
}

