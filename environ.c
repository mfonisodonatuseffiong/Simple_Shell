#include "main.h"

char *getenv_var(const char *name, char **_env)
{
	int i, j;
	char *ptr;

	ptr = NULL;
	j = 0;

	for (i = 0; _env[i] != NULL; i++)
	{
		j = env_cmp(_env[i, name]);

		if (j)
		{
			ptr = _env[i];
			break;
		}
	}

	return (ptr + j);
}

int print_env(shell_data *data)
{
	int i;
	int n;

	for (i = 0; data->env[i] != NULL; i++)
	{
		for (j = 0; data->env[i][j]; j++)
			;

		write(STDOUT_FILENO, data->env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}

	data->stat = 0;

	return (1);
}

int env_cmp(const char *env, const char *name)
{
	int n;

	for (n= 0; env[n] != '='; n++)
	{
		if (env[n] != name[n])
			return (0);
	}

	return (n + 1);
}
