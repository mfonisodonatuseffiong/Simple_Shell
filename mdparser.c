#include "shell.h"

/**
 * md_parser - Parses a command line into an array of arguments.
 * @md_line: The command line.
 *
 * Return: Array of arguments or NULL on failure.
 */
char **md_parser(char *md_line)
{
	char **md_args = NULL;
	char *md_token = NULL;
	int md_argc = 0;

	if (!md_line)
		return (NULL);

	/* Allocate space for an array of char pointers */
	md_args = malloc(sizeof(char *));
	if (!md_args)
		return (NULL);

	/* Tokenize the input line and store each token as an argument */
	md_token = strtok(md_line, " \t\r\n\a");
	while (md_token)
	{
		/* Reallocate space for an additional argument */
		char **md_tmp = realloc(md_args, (md_argc + 1) * sizeof(char *));
		if (!md_tmp)
		{
			free(md_args);
			return (NULL);
		}
		md_args = md_tmp;

		/* Store the token as an argument */
		md_args[md_argc] = md_strdup(md_token);
		if (!md_args[md_argc])
		{
			md_free_args(md_args); /* Free allocated memory on failure */
			return (NULL);
		}

		/* Increment argument count and tokenize the next token */
		md_argc++;
		md_token = strtok(NULL, " \t\r\n\a");
	}

	/* Add a NULL pointer to the end of the array to indicate the end of arguments */
	char **md_tmp = realloc(md_args, (md_argc + 1) * sizeof(char *));
	if (!md_tmp)
	{
		free(md_args);
		return (NULL);
	}
	md_args = md_tmp;
	md_args[md_argc] = NULL;

	return (md_args);
}

