#include "main.h"
#include "main.h"
/**
 * print_environment - Function that ptint env command
 *
 * Return: .
*/
void print_environment(void)
{
	char **env_var = cu_environ;
	int length;

	while ((*env_var))
	{
		length = (int)_strlen(*env_var);
		write(1, *env_var, len);
		write(1, "\n", 1);
		env_var++;
	}
}
