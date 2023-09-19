#include "shell.h"

/**
 * md_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int md_history(info_t *info)
{
	print_list(info->md_history);
	return (0);
}

/**
 * md_unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int md_unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->md_alias),
		get_node_index(info->md_alias, node_starts_with(info->md_alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * md_set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int md_set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (md_unset_alias(info, str));

	md_unset_alias(info, str);
	return (add_node_end(&(info->md_alias), str, 0) == NULL);
}

/**
 * md_print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int md_print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * md_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int md_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->md_argc == 1)
	{
		node = info->md_alias;
		while (node)
		{
			md_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->md_argv[i]; i++)
	{
		p = _strchr(info->md_argv[i], '=');
		if (p)
			md_set_alias(info, info->md_argv[i]);
		else
			md_print_alias(node_starts_with(info->md_alias, info->md_argv[i], '='));
	}

	return (0);
}

