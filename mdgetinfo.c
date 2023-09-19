#include "shell.h"

/**
 * md_clear_info - initializes info_t struct
 * @md_info: struct address
 */
void md_clear_info(info_t *md_info)
{
	md_info->md_arg = NULL;
	md_info->md_argv = NULL;
	md_info->md_path = NULL;
	md_info->md_argc = 0;
}

/**
 * md_set_info - initializes info_t struct
 * @md_info: struct address
 * @md_av: argument vector
 */
void md_set_info(info_t *md_info, char **md_av)
{
	int md_i = 0;

	md_info->md_fname = md_av[0];
	if (md_info->md_arg)
	{
		md_info->md_argv = strtow(md_info->md_arg, " \t");
		if (!md_info->md_argv)
		{
			md_info->md_argv = malloc(sizeof(char *) * 2);
			if (md_info->md_argv)
			{
				md_info->md_argv[0] = _strdup(md_info->md_arg);
				md_info->md_argv[1] = NULL;
			}
		}
		for (md_i = 0; md_info->md_argv && md_info->md_argv[md_i]; md_i++)
			;
		md_info->md_argc = md_i;

		replace_alias(md_info);
		replace_vars(md_info);
	}
}

/**
 * md_free_info - frees info_t struct fields
 * @md_info: struct address
 * @all: true if freeing all fields
 */
void md_free_info(info_t *md_info, int all)
{
	ffree(md_info->md_argv);
	md_info->md_argv = NULL;
	md_info->md_path = NULL;
	if (all)
	{
		if (!md_info->md_cmd_buf)
			free(md_info->md_arg);
		if (md_info->md_env)
			free_list(&(md_info->md_env));
		if (md_info->md_history)
			free_list(&(md_info->md_history));
		if (md_info->md_alias)
			free_list(&(md_info->md_alias));
		ffree(md_info->md_environ);
		md_info->md_environ = NULL;
		bfree((void **)md_info->md_cmd_buf);
		if (md_info->md_readfd > 2)
			close(md_info->md_readfd);
		_putchar(BUF_FLUSH);
	}
}

