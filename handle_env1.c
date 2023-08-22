#include "shell"

/**
 * getenv_handler - get an environment variable
 * @name: name of the environment variable
 * @env_x: environment variable
 *
 * Return: value of the environment variable if it is found.
 * Otherwise, returns NULL.
 */
char *getenv_handler(char *name, char **env_x)
{
	char *p = NULL;
	int i, n, j;

	for (i = 0; env_x[i]; i++)
	{
		n = 0;
		for (j = 0; env_x[i][j] != '='; j++)
		{
			if (env_x[i][j] != name[j])
			{
				n = 0;
				break;
			}
		}
		if (env_x[i][j] == '=' && name[j] == '\0')
		{
			n = j + 1;
		}
		if (n)
		{
			p = env_x[i];
			break;
		}
	}

	return ((p) ? p + n : NULL);
}

/**
 * env_x - a function that prints the evironment variables
 * @Data: the data
 * Return: 1
 */

int env_x(data *Data)
{
	int i, size;

	for (i = 0; Data->env[i]; i++)
	{
		size = str_len(Data->env[i]);
		write(STDOUT_FILENO, Data->env[i], size);
		write(STDOUT_FILENO, "\n", 1);
	}
	Data->status = 0;
	return (1);
}
