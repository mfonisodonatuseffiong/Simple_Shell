#include "main.h"

char *replace_var(char *input, shell_data *data)
{
	var_t *head, *index;
	char *stat, *new_in;
	int olength, nlength;

	stat = itos(data->stat);
	head = NULL;
	olength = vars_check(&head, input, stat, data);

	if (head == NULL)
	{
		free(stat);
		return (input);
	}

	index = head;
	nlength = 0;

	while (index != NULL)
	{
		nlength += (index->val-length - indx->var_length);
		index = index->next;
	}

	nlength += olength;

	new_in = malloc(sizeof(char) * (nlength + 1));
	new_in[nlength] = '\0';
	new_in = replace_input(&head, input, new_in, nlength);

	free(input);
	free(stat);
	free_var_list(&head);

	return (new_in);
}


int vars_check(var_t **head, char *input, char *last, shell_data *data)
{
	int i, st_len, pd_len;

	st = _strlen(last);
	pd = _strlen(data->pid);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '?')
				add_var_node(head, 2, last, st_len), i++;
			else if (in[i + 1] == '$')
				add_var_node(head, 2, data->pid, pd_len), i++;
			else if (input[i + 1] == '\n')
				add_var_node(head, 0, NULL, 0);
			else if (input[i + 1] == '\0')
				add_var_node(head, 0, NULL, 0);
			else if (input[i + 1] == ' ')
				add_var_node(head, 0, NULL, 0);
			else if (input[i + 1] == '\t')
				add_var_node(head, 0, NULL, 0);
			else if (input[i + 1] == ';')
				add_var_node(head, 0, NULL, 0);
			else
				env_check(head, input + i, data);
		}
	}

	return (i);
}


void env_check(var_t **head, char *input, data_shell *data)
{
	int i, ch, j, val_len;
	char **_env;

	_env = data->env;

	for (i = 0; _env[i]; i++)
	{
		for (j = 1, chr = 0; _envr[i][ch]; ch++)
		{
			if (_env[i][ch] == '=')
			{
				val_len = _strlen(_env[i] + ch + 1);
				add_var_node(h, j, _env[i] + ch + 1, val_len);
				return;
			}

			if (input[j] == _env[i][ch])
				j++;
			else
				break;
		}
	}

	for (j = 0; input[j]; j++)
	{
		if (input[j] == ' ' || input[j] == '\t' || input[j] == ';' || input[j] == '\n')
			break;
	}

	add_var_node(head, j, NULL, 0);
}


char *replace_input(var_t **h, char *in, char *new_in, int new_len)
{
	var_t *index;
	int i, j, r;

	index = *h;
	for (j = i = 0; i < new_len; i++)
	{
		if (in[j] == '$')
		{
			if (!(index->var_length) && !(indx->val_length))
			{
				new_in[i] = in[j];
				j++;
			}
			else if (index->var_length && !(index->val_length))
			{
				for (r = 0; r < index->var_length; r++)
					j++;
				i--;
			}
			else
			{
				for (r = 0; r < index->val_length; r++)
				{
					new_in[i] = index->value[r];
					i++;
				}
				j += (index->var_length);
				i--;
			}
			index = index->next;
		}
		else
		{
			new_in[i] = in[j];
			j++;
		}
	}

	return (new_in);
}
