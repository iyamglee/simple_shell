#include "shell.h"

/**
 * _printf - print array of char in stdio
 * @string: ptr to array printed
 * Return: num of printed bytes,-1 on error
 */
int _printf(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * _printf - print array of char in stdio
 * @string: ptr to the array
 * Return: num of bytes printed, -1 on error
 */
int _printf(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - print array of char in stdio
 * @data: program struct ptr
 * @errorcode: error code
 * Return: num of bytes printed, -1 on error.
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printf(data->program_name);
		_printf(": ");
		_printf(n_as_string);
		_printf(": ");
		_printf(data->tokens[0]);
		if (errorcode == 2)
			_printf(": Illegal number: ");
		else
			_printf(": can't cd to ");
		_printf(data->tokens[1]);
		_printf("\n");
	}
	else if (errorcode == 127)
	{
		_printf(data->program_name);
		_printf(": ");
		_printf(n_as_string);
		_printf(": ");
		_printf(data->command_name);
		_printf(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printf(data->program_name);
		_printf(": ");
		_printf(n_as_string);
		_printf(": ");
		_printf(data->command_name);
		_printf(": Permission denied\n");
	}
	return (0);
}
