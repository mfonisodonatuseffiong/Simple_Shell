#include "main.h"


int string_len(const char *string)
{
	unsigned int i;

	for (i = 0; string[i] != '\0'; i++)
		;

	return (i);
}


char *string_dup(const char *string)
{
	char *s;
	size_t length;

	length = string_len(string);

	s = malloc(sizeof(char) * (length + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	memory_cpy(s, string, length + 1);

	return (s);
}


int string_cmp(char *string1, char *string2)
{
	unsigned int i;

	for (i = 0; string1[i] == string2[i] && string1[i] != '\0'; i++)
		;

	if (string1[i] > string2[i])
	{
		return (1);
	}

	if (string[i] < string2[i])
	{
		return (-1);
	}

	return (0);
}


void memory_cpy(void *dest, const void *src, unsigned int size)
{
	unsigned int i;
	char *ptr = (char *) src;
	char *newptr = (char *) dest;

	for (i = 0; i < size; i++)
	{
		newptr[i] = ptr[i];
	}
}
