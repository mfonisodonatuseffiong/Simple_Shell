#include "shell.h"

/**
 * md_getline - reads the next line from the standard input
 * @md_info: pointer to info_t structure
 *
 * Return: pointer to the read line, NULL on EOF
 */
char *md_getline(info_t *md_info)
{
	char *md_line = NULL;
	size_t md_len = 0;
	ssize_t md_read;

	if (!isatty(STDIN_FILENO))
	{
		return (md_getline_file(md_line));
	}

	if (md_info->md_linecount_flag)
	{
		print_prompt(md_info->md_path, md_info->md_linecount++);
		md_info->md_linecount_flag = 0;
	}

	signal(SIGINT, md_sigintHandler);
	md_read = getline(&md_line, &md_len, stdin);
	if (md_read == -1)
	{
		return (md_handle_eof(md_line));
	}

	if (md_read > 0 && md_line[md_read - 1] == '\n')
	{
		md_line[md_read - 1] = '\0'; /* Remove the trailing newline */
		md_read--;
	}
	else if (md_read == 0)
	{
		return (md_handle_eof(md_line));
	}

	return (md_line);
}

/**
 * md_handle_eof - handles the EOF condition
 * @md_line: the line to handle
 *
 * Return: pointer to the line or NULL
 */
char *md_handle_eof(char *md_line)
{
	if (md_line)
		free(md_line);
	_putchar('\n');
	return (NULL);
}

/**
 * md_getline_file - reads a line from a non-interactive file
 * @md_line: pointer to a char pointer
 *
 * Return: pointer to the read line or NULL
 */
char *md_getline_file(char *md_line)
{
	if (getline(&md_line, &md_len, stdin) == -1)
	{
		if (md_line)
			free(md_line);
		return (NULL);
	}
	return (md_line);
}

