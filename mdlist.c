#include "shell.h"

/**
 * md_add_node - adds a node to the start of the list
 * @md_head: address of pointer to head node
 * @md_str: str field of node
 * @md_num: node index used by history
 *
 * Return: pointer to the newly added node, or NULL on failure
 */
list_t *md_add_node(list_t **md_head, const char *md_str, int md_num)
{
	list_t *md_new_head;

	if (!md_head)
		return (NULL);

	md_new_head = malloc(sizeof(list_t));
	if (!md_new_head)
		return (NULL);

	md_memset((void *)md_new_head, 0, sizeof(list_t));
	md_new_head->num = md_num;

	if (md_str)
	{
		md_new_head->str = md_strdup(md_str);
		if (!md_new_head->str)
		{
			free(md_new_head);
			return (NULL);
		}
	}

	md_new_head->next = *md_head;
	*md_head = md_new_head;
	return (md_new_head);
}

/**
 * md_add_node_end - adds a node to the end of the list
 * @md_head: address of pointer to head node
 * @md_str: str field of node
 * @md_num: node index used by history
 *
 * Return: pointer to the newly added node, or NULL on failure
 */
list_t *md_add_node_end(list_t **md_head, const char *md_str, int md_num)
{
	list_t *md_new_node, *md_node;

	if (!md_head)
		return (NULL);

	md_node = *md_head;
	md_new_node = malloc(sizeof(list_t));
	if (!md_new_node)
		return (NULL);

	md_memset((void *)md_new_node, 0, sizeof(list_t));
	md_new_node->num = md_num;

	if (md_str)
	{
		md_new_node->str = md_strdup(md_str);
		if (!md_new_node->str)
		{
			free(md_new_node);
			return (NULL);
		}
	}

	if (md_node)
	{
		while (md_node->next)
			md_node = md_node->next;
		md_node->next = md_new_node;
	}
	else
		*md_head = md_new_node;

	return (md_new_node);
}

/**
 * md_print_list_str - prints only the str element of a list_t linked list
 * @md_h: pointer to first node
 *
 * Return: number of nodes in the list
 */
size_t md_print_list_str(const list_t *md_h)
{
	size_t md_i = 0;

	while (md_h)
	{
		md_puts(md_h->str ? md_h->str : "(nil)");
		md_puts("\n");
		md_h = md_h->next;
		md_i++;
	}
	return (md_i);
}

/**
 * md_delete_node_at_index - deletes a node at a given index
 * @md_head: address of pointer to first node
 * @md_index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int md_delete_node_at_index(list_t **md_head, unsigned int md_index)
{
	list_t *md_node, *md_prev_node;
	unsigned int md_i = 0;

	if (!md_head || !*md_head)
		return (0);

	if (!md_index)
	{
		md_node = *md_head;
		*md_head = (*md_head)->next;
		free(md_node->str);
		free(md_node);
		return (1);
	}

	md_node = *md_head;
	while (md_node)
	{
		if (md_i == md_index)
		{
			md_prev_node->next = md_node->next;
			free(md_node->str);
			free(md_node);
			return (1);
		}
		md_i++;
		md_prev_node = md_node;
		md_node = md_node->next;
	}

	return (0);
}

/**
 * md_free_list - frees all nodes of a list
 * @md_head_ptr: address of pointer to head node
 *
 * Return: void
 */
void md_free_list(list_t **md_head_ptr)
{
	list_t *md_node, *md_next_node, *md_head;

	if (!md_head_ptr || !*md_head_ptr)
		return;

	md_head = *md_head_ptr;
	md_node = md_head;
	while (md_node)
	{
		md_next_node = md_node->next;
		free(md_node->str);
		free(md_node);
		md_node = md_next_node;
	}

	*md_head_ptr = NULL;
}

