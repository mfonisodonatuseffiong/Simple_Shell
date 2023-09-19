#include "shell.h"

/**
 * md_list_len - determines the length of a linked list
 * @md_h: pointer to the first node
 *
 * Return: size of the list
 */
size_t md_list_len(const list_t *md_h)
{
	size_t md_i = 0;

	while (md_h)
	{
		md_h = md_h->next;
		md_i++;
	}
	return (md_i);
}

/**
 * md_list_to_strings - returns an array of strings of the list->str
 * @md_head: pointer to the first node
 *
 * Return: array of strings
 */
char **md_list_to_strings(list_t *md_head)
{
	list_t *md_node = md_head;
	size_t md_i = md_list_len(md_head), j;
	char **md_strs;
	char *md_str;

	if (!md_head || !md_i)
		return (NULL);
	md_strs = malloc(sizeof(char *) * (md_i + 1));
	if (!md_strs)
		return (NULL);
	for (md_i = 0; md_node; md_node = md_node->next, md_i++)
	{
		md_str = malloc(md_strlen(md_node->md_str) + 1);
		if (!md_str)
		{
			for (j = 0; j < md_i; j++)
				free(md_strs[j]);
			free(md_strs);
			return (NULL);
		}

		md_str = md_strcpy(md_str, md_node->md_str);
		md_strs[md_i] = md_str;
	}
	md_strs[md_i] = NULL;
	return (md_strs);
}

/**
 * md_print_list - prints all elements of a list_t linked list
 * @md_h: pointer to the first node
 *
 * Return: size of the list
 */
size_t md_print_list(const list_t *md_h)
{
	size_t md_i = 0;

	while (md_h)
	{
		md_puts(md_convert_number(md_h->md_num, 10, 0));
		md_putchar(':');
		md_putchar(' ');
		md_puts(md_h->md_str ? md_h->md_str : "(nil)");
		md_puts("\n");
		md_h = md_h->next;
		md_i++;
	}
	return (md_i);
}

/**
 * md_node_starts_with - returns the node whose string starts with prefix
 * @md_node: pointer to the list head
 * @md_prefix: string to match
 * @md_c: the next character after prefix to match
 *
 * Return: matching node or NULL
 */
list_t *md_node_starts_with(list_t *md_node, char *md_prefix, char md_c)
{
	char *md_p = NULL;

	while (md_node)
	{
		md_p = md_starts_with(md_node->md_str, md_prefix);
		if (md_p && ((md_c == -1) || (*md_p == md_c)))
			return (md_node);
		md_node = md_node->next;
	}
	return (NULL);
}

/**
 * md_get_node_index - gets the index of a node
 * @md_head: pointer to the list head
 * @md_node: pointer to the node
 *
 * Return: index of the node or -1
 */
ssize_t md_get_node_index(list_t *md_head, list_t *md_node)
{
	size_t md_i = 0;

	while (md_head)
	{
		if (md_head == md_node)
			return (md_i);
		md_head = md_head->next;
		md_i++;
	}
	return (-1);
}

