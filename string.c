#include "shell.h"

/**
 * md_strlen - returns the length of a string
 * @md_s: the string whose length to check
 *
 * Return: integer length of string
 */
int md_strlen(char *md_s)
{
	int md_i = 0;

	if (!md_s)
		return (0);

	while (*md_s++)
		md_i++;
	return (md_i);
}

/**
 * md_strcmp - performs lexicographic comparison of two strings.
 * @md_s1: the first string
 * @md_s2: the second string
 *
 * Return: negative if md_s1 < md_s2, positive if md_s1 > md_s2, zero if md_s1 == md_s2
 */
int md_strcmp(char *md_s1, char *md_s2)
{
	while (*md_s1 && *md_s2)
	{
		if (*md_s1 != *md_s2)
			return (*md_s1 - *md_s2);
		md_s1++;
		md_s2++;
	}
	if (*md_s1 == *md_s2)
		return (0);
	else
		return (*md_s1 < *md_s2 ? -1 : 1);
}

/**
 * md_starts_with - checks if needle starts with haystack
 * @md_haystack: string to search
 * @md_needle: the substring to find
 *
 * Return: address of the next character of haystack or NULL
 */
char *md_starts_with(const char *md_haystack, const char *md_needle)
{
	while (*md_needle)
		if (*md_needle++ != *md_haystack++)
			return (NULL);
	return ((char *)md_haystack);
}

/**
 * md_strcat - concatenates two strings
 * @md_dest: the destination buffer
 * @md_src: the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *md_strcat(char *md_dest, char *md_src)
{
	char *md_ret = md_dest;

	while (*md_dest)
		md_dest++;
	while (*md_src)
		*md_dest++ = *md_src++;
	*md_dest = *md_src;
	return (md_ret);
}

