#include "shell.h"

/**
 * md_history_add - adds a command to the history
 * @md_info: parameter struct
 * @line: the command line to add
 *
 * Return: always 0
 */
int md_history_add(info_t *md_info, const char *line)
{
	int index;
	char *cmd;

	if (!md_info || !line)
		return (0);

	index = md_info->hist_count % MD_HISTORY_SIZE;
	if (md_info->hist[index])
		free(md_info->hist[index]);

	cmd = _strdup(line);
	if (!cmd)
		return (0);

	md_info->hist[index] = cmd;
	md_info->hist_count++;

	return (0);
}

/**
 * md_history_print - prints the history list
 * @md_info: parameter struct
 *
 * Return: always 0
 */
int md_history_print(info_t *md_info)
{
	int i;

	if (!md_info)
		return (0);

	for (i = 0; i < MD_HISTORY_SIZE; i++)
	{
		if (md_info->hist[i])
			_printf("%6d  %s\n", i, md_info->hist[i]);
	}

	return (0);
}

