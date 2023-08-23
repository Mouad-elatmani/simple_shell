#include "shel.h"
/**
 * run_interactive_shell - Function to execute program in interactive mode.
 * @arguments: The argument vector.
 * Return: None.
 */
void run_interactive_shell(char **arguments)
{
	    char *input_line = NULL, *cmd, *processed_line;
	    char **cmd_arguments = {NULL}, *env[] = {NULL};
	    size_t buffer_size = 0;
	    ssize_t read_size;
	    int process_status = 0, command_count = 0, i;

	    while (1)
	   {
		    command_count++;
		    write(1, "$ ", sizeof("$ ") - 1);
		    read_size = cu_getline(&input_line, &buffer_size, stdin);
		    if (read_size == -1)
		    {
			     write(1, "\n", 1);
			     break;
		    }
		     processed_line = new_line_handler(input_line);
		     cmd = find_executable(processed_line);
		     if (_strcmp(processed_line, "\n") == 0 || processed_line[0] == '#')
			     continue;
		     else if (check_builtin(arguments[0], processed_line, &process_status, command_count, input_line) != -1)
		     {
			      free(cmd);
			      continue;
		     }
		      else if (cmd != NULL)
		      {
			      cmd_arguments = generate_arguments(processed_line);
			       i = execute_command(cmd, cmd_arguments, env, &process_status);
			       if (i == 0)
				       print_cu_error(arguments[0], command_count, process_status, processed_line);
		      }
		      else if (cmd == NULL)
		      {
			      _execute_not_found(processed_line, cmd_arguments, env, &process_status);
			      print_cu_error(arguments[0], command_count, process_status, processed_line);
		      }
		      free(cmd);
	    }
	    free(input_line);
}

