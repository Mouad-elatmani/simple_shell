#include "shel.h"
/**
 * main - Main function to run the SHELL program
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: Exit status
 */

int main(int argc, char **argv)
{
	char *line;
	size_t len;

	if (argc > 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (1);
	}

	if (isatty(STDIN_FILENO))
	{
		line = NULL;
		len = 0;

		while (1)
		{
			printf("($) ");
			if (getline(&line, &len, stdin) == -1)
			{
			break;
			}

			if (strcmp(line, "exit\n") == 0)
			{
			free(line);
			exit(0);
			}

			system(line);
		}

		free(line);
	}
	else
	{
		run_non_interactive_mode(argv);
	}

	return (0);
}

