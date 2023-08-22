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
		length = (int)str_len(*env_var);
		write(1, *env_var, len);
		write(1, "\n", 1);
		env_var++;
	}
}
/**
 * _get_envi_value - Function that get the value of a variable.
 * @name: Variable name.
 * Return: The value of the variable.
 */
char *_get_envi_value(char *name)
{
	int var;
	char **environment;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	var = (int)str_len(name);

	for (environment = cu_environ; (*environment) != NULL; environment++)
	{
		if (strncmp(*environment, name, var) == 0 && (*environment)[var] == '=')
			return (*environment + var + 1);
	}
}
