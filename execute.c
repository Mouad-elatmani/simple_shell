#include "shel.h"
void _execute_not_found(char *command_path, char **cmd_argv,
		char *environment[], int *status)
{
	int execution_result;
	int process_id;

	process_id = fork();
	if (process_id == -1)
		perror("ERROR IN FORK");
	if (process_id == 0)
	{
		execution_result = execve(command_path, cmd_argv, environment);
		if (execution_result == -1)
			exit(127);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		*status = WEXITSTATUS(*status);
	}
}
