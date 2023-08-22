#include "shell.h"

/**
 * error_handler - a function that prints the error according the builtin
 * @Data: the data we gonna use
 * @val: the value of error
 * Return: the err
 */

int error_handler(data *Data, int val)
{
	char *err;

	switch (val)
	{
		case -1:
			err = handle_env_err(Data);
			break;
		case 126:
			err = handle_path126_err(Data);
			break;
		/*
		 * case 127:
			err = error_not_found(Data);
			break;
		*/
		case 2:
			if (str_cmp("exit", Data->arg_s[0]) == 0)
				err = handle_exit_err(Data);

			/*
			 * else if (str_cmp("cd", Data->arg_s[0]) == 0)
				err = error_get_cd(Data);
			*/
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, str_len(err));
		free(err);
	}

	Data->status = val;
	return (val);
}
