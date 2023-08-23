#include "shell.h"

/**
 * if_curr_dir - a functuion that checks ":" is in the curr dir
 * @path: the path
 * @a: the index
 * Return: 1 or 0
 */

int if_curr_dir(char *path, int *a)
{
	char *p = path + *a;

	if (*p == ':')
	{
		return (1);
	}
	while (*p && *p != ':')
	{
		p++;
	}
	if (*p == ':')
	{
		p++;
	}
	*a = p - path;
	return (0);
}

/**
 * find_cmd - a function that locates a cmd
 * @cmd: the command
 * @env: env var
 * Return: the location of cmd
 */

char *find_cmd(char *cmd, char **env)
{
	char *path, *p, *tok, *s;
	char dir[1024];
	struct stat data;

	path = getenv_handler("PATH", env);
	if (path)
	{
		p = str_dup(path);
		tok = strtok_handler(p, ":");
		while (tok != NULL)
		{
			str_cpy(dir, tok);
			str_cat(dir, "/");
			str_cat(dir, cmd);

			if (stat(dir, &data) == 0 && (data.st_mode & S_IXUSR))
			{
				free(p);
				return (str_dup(dir));
			}
			tok = strtok_handler(NULL, ":");
		}
		free(p);
	}
	if (cmd[0] == '/' || str_chr(cmd, ':'))
	{
		if (stat(cmd, &data) == 0 && (data.st_mode & S_IXUSR))
		{
			return (str_dup(cmd));
		}
	}

	return (NULL);
}

/**
 * if_executes - a function that checks if a cmd is executable
 * @Data: the data
 * Return: 0 or -1 or another number
 */

int if_executes(data *Data)
{
	struct stat dt;
	char *inp = Data->arg_s[0];

	if (str_cmp(inp, ".") == 0)
	{
		return (0);
	}
	if (str_cmp(inp, "..") == 0)
	{
		return (0);
	}
	if (str_ncmp(inp, "../", 3) == 0)
	{
		return (0);
	}
	if (str_ncmp(inp, "./", 2) == 0)
	{
		inp += 2;
	}
	if (inp[0] == '/')
	{
		if (stat(inp, &dt) == 0)
		{
			return (inp - Data->arg_s[0]);
		}
		else
		{
			error_handler(Data, 127);
			return (-1);
		}
	}
	if (stat(inp, &dt) == 0)
	{
		return (inp - Data->arg_s[0]);
	}

	error_handler(Data, 127);
	return (-1);
}

/**
 * handle_error_cmd - handle per for cmd
 * @dir: the directory
 * @Data: the data
 * Return: a number
 */

int handle_error_cmd(char *dir, data *Data)
{
	char *path;

	if (!dir)
	{
		error_handler(Data, 127);
		return (1);
	}
	path = (str_cmp(Data->arg_s[0], dir) != 0) ? dir : Data->arg_s[0];
	if (access(path, X_OK) == -1)
	{
		error_handler(Data, 126);
		if (path == dir)
			free(dir);
		return (1);
	}
	if (dir && dir != Data->arg_s[0])
		free(dir);
	return (0);
}

/**
 * exec_cmd - a function that executes cmd
 * @Data: the data
 * Return: a number
 */

int exec_cmd(data *Data)
{
	pid_t pid;
	int s;
	char *dir;
	int exec;

	exec = if_executes(Data);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = find_cmd(Data->arg_s[0], Data->env);
		if (dir == NULL || handle_error_cmd(dir, Data) == 1)
			return (1);
	}
	else
	{
		dir = Data->arg_s[0];
	}

	pid = fork();
	if (pid == 0)
	{
		execve(dir + exec, Data->arg_s, Data->env);
		exit(1);
	}
	else if (pid < 0)
	{
		perror(Data->arg_v[0]);
		return (1);
	}
	else
	{
		do {
			waitpid(pid, &s, WUNTRACED);
		} while (!WIFEXITED(s) && !WIFSIGNALED(s));
	}

	Data->status = s / 256;
	return (1);
}

