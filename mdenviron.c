/**
 * md_myenv - prints the current environment
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_myenv(info_t *md_info)
{
	print_list_str(md_info->env);
	return (0);
}

/**
 * md_getenv - gets the value of an environ variable
 * @md_info: Structure containing potential arguments. Used to maintain
 * @md_name: env var name
 *
 * Return: the value
 */
char *md_getenv(info_t *md_info, const char *md_name)
{
	list_t *md_node = md_info->env;
	char *md_p;

	while (md_node)
	{
		md_p = starts_with(md_node->str, md_name);
		if (md_p && *md_p)
			return (md_p);
		md_node = md_node->next;
	}
	return (NULL);
}

/**
 * md_mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_mysetenv(info_t *md_info)
{
	if (md_info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(md_info, md_info->argv[1], md_info->argv[2]))
		return (0);
	return (1);
}

/**
 * md_myunsetenv - Remove an environment variable
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_myunsetenv(info_t *md_info)
{
	int md_i;

	if (md_info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (md_i = 1; md_i <= md_info->argc; md_i++)
		_unsetenv(md_info, md_info->argv[md_i]);

	return (0);
}

/**
 * md_populate_env_list - populates env linked list
 * @md_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_populate_env_list(info_t *md_info)
{
	list_t *md_node = NULL;
	size_t md_i;

	for (md_i = 0; environ[md_i]; md_i++)
		add_node_end(&md_node, environ[md_i], 0);
	md_info->env = md_node;
	return (0);
}

