#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @str: the input string to tokenize
 * @delim: the delimiter used to split the string
 *
 * Return: an array of tokens (strings)
 */
char **tokenize(char *str, const char *delim)
{
	int i, num_tokens = 0;
	char **tokens = NULL;
	char *token = strtok(str, delim);

	while (token)
	{
		num_tokens++;
		tokens = _realloc(tokens, sizeof(char *) * (num_tokens - 1),
		                 sizeof(char *) * num_tokens);
		if (!tokens)
			return (NULL);
		tokens[num_tokens - 1] = token;
		token = strtok(NULL, delim);
	}

	tokens = _realloc(tokens, sizeof(char *) * num_tokens,
	                 sizeof(char *) * (num_tokens + 1));
	if (!tokens)
		return (NULL);
	tokens[num_tokens] = NULL;

	return (tokens);
}

