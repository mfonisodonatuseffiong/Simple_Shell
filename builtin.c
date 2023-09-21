#include "main.h"


int (get_built(char *command))(shell_data *)
{
	unsigned int i;

	cmd_builtin builtin[] = {
		{"exit", shell_exit},
		{NULL, NULL}
	}

	for (i = 0; cmd_builtin[i].name != NULL; i++)
	{
		if (string_cmp(builtin[i].name, command) == 0)
		{
			break;
		}
	}

	return (builtin[i].function);
}
