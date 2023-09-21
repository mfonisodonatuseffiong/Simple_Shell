#include "main.h"

int main(int argc, char **argv)
{
	shell_data data;
	(void) argc;

	signal(SIGINT, get_signint);
	set_data(&data, argv);
	_shell(&data);
	free_data(&data);

	if (data.stat < 0)
	{
		return (255);
	}

	return (data.stat);
}


void set_data(shell_data *data, char **argv)
{
	unsigned int i;
	unsigned int n = 0;

	data->argv = argv;
	data->input = NULL;
	data->arguments = NULL;
	data->stat = 0;
	data->count = 1;

	for (i = 0; environ[i] != NULL; i++)
	{
		n++;
	}

	data->env = malloc(sizeof(char *) * (n + 1));

	for (i = 0; environ[i] != NULL; i++)
	{
		data->env[i] = string_dup(environ[i]);
	}

	data->env[i] = NULL;
	data->pid = _itos(getpid());
}


void free_data(shell_data *data)
{
	unsigned int i;

	for (i = 0; data->env[i] != NULL; i++)
	{
		free(data->env[i]);
	}

	free(data->env);
	free(data->pid);
}
