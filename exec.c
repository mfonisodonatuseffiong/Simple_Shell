#include "main.h"

int find_exec(shell_data data)
{
	int (*builtin)(shell_data *data);

	if (data->arguments[0] == NULL)
	{
		return (1);
	}

	builtin = get_built(data->arguments[0]);

	if (builtin != NULL)
	{
		return (builtin(data));
	}

	return (exec_command(data));
}
