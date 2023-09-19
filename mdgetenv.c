#include "shell.h"

/**
 * md_get_environ - returns the string array copy of our environ
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
char **md_get_environ(info_t *md_info)
{
	if (!md_info->environ || md_info->env_changed)
	{
		md_info->environ = list_to_strings(md_info->env);
		md_info->env_changed = 0;
	}

	return (md_info->environ);
}

/**
 * md_unsetenv - Remove an environment variable
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @md_var: the string env var property
 * Return: 1 on delete, 0 otherwise
 */
int md_unsetenv(info_t *md_info, char *md_var)
{
	list_t *md_node = md_info->env;
	size_t md_i = 0;
	char *md_p;

	if (!md_node || !md_var)
		return (0);

	while (md_node)
	{
		md_p = starts_with(md_node->str, md_var);
		if (md_p && *md_p == '=')
		{
			md_info->env_changed = delete_node_at_index(&(md_info->env), md_i);
			md_i = 0;
			md_node = md_info->env;
			continue;
		}
		md_node = md_node->next;
		md_i++;
	}
	return (md_info->env_changed);
}

/**
 * md_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @md_var: the string env var property
 * @md_value: the string env var value
 * Return: Always 0
 */
int md_setenv(info_t *md_info, char *md_var, char *md_value)
{
	char *md_buf = NULL;
	list_t *md_node;
	char *md_p;

	if (!md_var || !md_value)
		return (0);

	md_buf = malloc(_strlen(md_var) + _strlen(md_value) + 2);
	if (!md_buf)
		return (1);
	_strcpy(md_buf, md_var);
	_strcat(md_buf, "=");
	_strcat(md_buf, md_value);
	md_node = md_info->env;
	while (md_node)
	{
		md_p = starts_with(md_node->str, md_var);
		if (md_p && *md_p == '=')
		{
			free(md_node->str);
			md_node->str = md_buf;
			md_info->env_changed = 1;
			return (0);
		}
		md_node = md_node->next;
	}
	add_node_end(&(md_info->env), md_buf, 0);
	free(md_buf);
	md_info->env_changed = 1;
	return (0);
}

