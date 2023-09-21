#include "main.h"

void insert_node(sep_t **sep_head, cmd_list **cmd_head, char *in)
{
	int n;
	char *string;

	in = char_swp(in, 0);

	for (n = 0; in[n]; n++)
	{
		if (in[n] == ';')
			insert_sep_node_end(sep_head, inp[n]);

		if (in[n] == '|' || in[n] == '&')
		{
			insert_sep_node_end(sep_head, in[n]);
			n++;
		}
	}

	string = string_tok(in, ";|&");

	do {
		string = char_swp(string, 1);
		insert_line_node_end(cmd_head, string);
		string = string_tok(NULL, ";|&");
	} while (string != NULL);
}

void _next(sep_t **s_list, cmd_list **l_list, shell_data data)
{
	int loop_s;
	sep_t *s_ls;
	cmd_list *l_ls;

	loop_s = 1;
	s_ls = *s_list;
	l_ls = *l_list;

	while (s_ls != NULL && loop_s)
	{
		if (data->stat == 0)
		{
			if (s_ls->sep == '&' || s_ls->sep == ';')
				loop_s = 0;
			if (s_ls->sep == '|')
				l_ls = l_ls->next, s_ls = s_ls->next;
		}
		else
		{
			if (s_ls->sep == '|' || s_ls->sep == ';')
				loop_s = 0;
			if (s_ls->sep == '&')
				l_ls = l_ls->next, s_ls = s_ls->next;
		}
		if (s_ls != NULL && !loop_s)
			s_ls = s_ls->next;
	}

	*s_list = s_ls;
	*l_list = l_ls;
}

char *char_swp(char *in, int bool)
{
	int n;

	if (bool == 0)
	{
		for (n = 0; in[n]; n++)
		{
			if (in[n] == '|')
			{
				if (in[n + 1] != '|')
					in[n] = 16;
				else
					n++;
			}

			if (in[n] == '&')
			{
				if (in[n + 1] != '&')
					in[n] = 12;
				else
					n++;
			}
		}
	}
	else
	{
		for (n = 0; in[n]; n++)
		{
			in[n] = (in[n] == 16 ? '|' : in[n]);
			in[n] = (in[n] == 12 ? '&' : in[n]);
		}
	}

	return (in);
}


int split_cmds(data_shell *data, char *input)
{
	int loop;
	sep_t *s_head, s_list;
	cmd_line l_head, l_list;

	s_head = NULL;
	l_head = NULL;

	insert_nodes(&s_head, &l_head, input);

	s_list = s_head;
	l_list = l_head;

	while (l_list != NULL)
	{
		data->input = l_list->line;
		data->arguments = split_line(data->input);
		loop = exec_line(data);
		free(data->arguments);

		if (loop == 0)
			break;

		_next(&s_list, &l_list, data);

		if (l_list != NULL)
			l_list = l_list->next;
	}

	free_sep_t(&s_head);
	free_cmd_list(&l_head);

	if (loop == 0)
		return (0);

	return (1);
}


char **split_line(char *input)
{
	size_t size;
	size_t n;
	char **toks;
	char *token;

	size = TOKEN_BUFFSIZE;
	toks = malloc(sizeof(char *) * (size));
	if (toks == NULL)
	{
		write(STDERR_FILENO, ":  allocation error\n", 19);
		exit(EXIT_FAILURE);
	}

	token = string_tok(input, DELIM);
	toks[0] = token;

	for (n = 1; token != NULL; n++)
	{
		if (n == size)
		{
			size += TOKEN_BUFFSIZE;
			toks = _realloc_dp(toks, n, sizeof(char *) * size);
			if (toks == NULL)
			{
				write(STDERR_FILENO, ":  allocation error\n", 19);
				exit(EXIT_FAILURE);
			}
		}
		token = string_tok(NULL, DELIM);
		toks[n] = token;
	}

	return (toks);
}
