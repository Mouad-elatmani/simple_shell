#include "sehl.h"
/**
 * _custom_getchar - a function that reads a character from standard input
 *
 * Return: the read character
 */
char _custom_getchar(void)
{
    char c;
    ssize_t read_result = read(STDIN_FILENO, &c, 1);

    if (read_result == -1)
    {
        perror("Reading Char");
        exit(EXIT_FAILURE);
    }
    else if (read_result == 0)
    {
        write(STDOUT_FILENO, "\n", 1);
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }

    return c;
}

/**
 * _custom_getline - a function to read a line from standard input
 * @line: a pointer to a pointer to save the string
 * @len: the size of the characters read
 *
 * Return: the size of the read string
 */
int _custom_getline(char **line, size_t *len)
{
    size_t limit = 25;
    char *tmp;

    *line = (char *)malloc(limit);
    if (!(*line))
    {
        perror("Allocation");
        exit(EXIT_FAILURE);
    }

    *len = 0;

    while ((*line)[*len - 1] != '\n')
    {
        (*line)[*len] = _custom_getchar();
        *len += 1;

        if (*len > (limit - 3))
        {
            tmp = (char *)realloc(*line, limit + 10);
            if (tmp)
                *line = tmp;
            else
            {
                perror("Reallocation");
                exit(EXIT_FAILURE);
            }
            limit += 10;
        }
    }

    return *len;
}
