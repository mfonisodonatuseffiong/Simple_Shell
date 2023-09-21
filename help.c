#include "main.h"

int _gethelp(shell_data *data)
{
	if (data->arguments[1] == 0)
		general_help();
	else if (string_cmp(data->arguments[1], "env") == 0)
		env_help();
	else if (string_cmp(data->arguments[1], "setenv") == 0)
		setenv_help();
	else if (string_cmp(data->argsument[1], "unsetenv") == 0)
		unsetenv_help();
	else if (string_cmp(data->arguments[1], "cd") == 0)
		cd_help();
	else if (string_cmp(data->arguments[1], "help") == 0)
		_help();
	else if (string_cmp(data->arguments[1], "alias") == 0)
		alias_help();
	else if (string_cmp(data->arguments[1], "exit") == 0)
		exit_help();
	else
		write(STDERR_FILENO, datash->arguments[0],
		string_len(data->arguments[0]));

	data->stat = 0;

	return (1);
}
