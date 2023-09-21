#include "main.h"

void _shell(shell_data *data)
{
	int loop = 1;
	int fe;
	char *input;

	while (loop == 1)
	{
		write(STDIN_FILENO, "^--^ ", 5);
		input = _read(&fe);
		
		if (fe != -1)
		{
			input = no_comment(input);

			if (input == NULL)
				continue;

			if (syntax_error(data, input) == 1)
			{
				data->stat = 2;
				free(input);
				continue;
			}

			input = replace_var(input, data);
			loop = split_cmds(data, input);
			data->count += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
}


char *no_comment(char *input)
{
	int i;
	int j = 0;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}

			if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
				j = i;
		}
	}

	if (j != 0)
	{
		input = _realloc(in, i, up_to + 1);
		input[j] = '\0';
	}

	return (j);
}
