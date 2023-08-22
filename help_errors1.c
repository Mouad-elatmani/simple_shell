#include "shell.h"

/**
 * handle_env_err - a function that handle error msf for env
 * @Data: the data we gonna use
 * Return: err msg
 */

char *handle_env_err(data *Data)
{
	int size;
	char *error, *p;
	char *vstr;
	const char *msg = ": Unable to add/remove from environment\n";

	/* Convert counter to string*/
	vstr = aux_itoa(Data->count);
	if (!vstr)
		return (NULL);
	/*  Calculate the required size for the full error message*/
	size = str_len(Data->arg_v[0]) + str_len(vstr);
	size += str_len(Data->arg_s[0]) + str_len(msg) + 4;
	/* Allocate memory for the error message*/
	error = malloc(sizeof(char) * (size + 1));
	if (!error)
	{
		free(vstr);
		return (NULL);
	}
	/* Build the error message manually using pointer arithmetic*/
	p = error;
	str_cpy(p, Data->arg_v[0]);
	p += str_len(Data->arg_v[0]);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, vstr);
	p += str_len(vstr);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, Data->arg_s[0]);
	p += str_len(Data->arg_s[0]);
	str_cpy(p, msg);
	/*Free the memory for vstr and return the error message*/
	free(vstr);
	return (error);
}

/**
 * handle_path126_err - a function that handle error message for path
 * @Data: the data we gonna use
 * Return: the err msg
 */

char *handle_path126_err(data *Data)
{
	int size;
	char *error, *p;
	char *vstr;
	const char *msg = ": Permission denied\n";

	/* Convert counter to string*/
	vstr = aux_itoa(Data->count);
	if (!vstr)
		return (NULL);
	/* Calculate the required length for the full error message*/
	size = str_len(Data->arg_v[0]) + str_len(vstr);
	size += str_len(Data->arg_s[0]) + str_len(msg) + 4;
	/* Allocate memory for the error message*/
	error = malloc(sizeof(char) * (size + 1));
	if (!error)
	{
		free(vstr);
		return (NULL);
	}
	p = error;
	str_cpy(p, Data->arg_v[0]);
	p += str_len(Data->arg_v[0]);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, vstr);
	p += str_len(vstr);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, Data->arg_s[0]);
	p += str_len(Data->arg_s[0]);
	str_cpy(p, msg);
	/* Free the memory for ver_str and return the error message*/
	free(vstr);
	return (error);
}
/**
 * handle_exit_err - handle exit err
 * @Data: the data we gonna use
 * Return: err's msg
 */

char *handle_exit_err(data *Data)
{
	int size;
	char *error, *p;
	char *vstr;
	const char *msg = ": Illegal number: ";

	/* Convert counter to string*/
	vstr = aux_itoa(Data->count);
	if (!vstr)
		return (NULL);
	/* Calculate the required length for the full error message*/
	size = str_len(Data->arg_v[0]) + str_len(vstr) + str_len(Data->arg_s[0]);
	size += str_len(Data->arg_s[1]) + str_len(msg) + 4;
	/* Allocate memory for the error message*/
	error = malloc(sizeof(char) * (size + 1));
	if (!error)
	{
		free(vstr);
		return (NULL);
	}
	p = error;
	str_cpy(p, Data->a_v[0]);
	p += str_len(Data->a_v[0]);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, vstr);
	p += str_len(vstr);
	str_cpy(p, ": ");
	p += 2;
	str_cpy(p, Data->arg_s[0]);
	p += str_len(Data->arg_s[0]);
	str_cpy(p, msg);
	p += str_len(msg);
	str_cpy(p, Data->arg_s[1]);
	p += str_len(Data->arg_s[1]);
	str_cpy(p, "\n");
	/* Free the memory for ver_str and return the error message*/
	free(vstr);
	return (error);
}

