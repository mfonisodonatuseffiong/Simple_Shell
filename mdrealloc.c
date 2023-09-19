#include "shell.h"

/**
 * md_memset - fills memory with a constant byte
 * @md_s: the pointer to the memory area
 * @md_b: the byte to fill *md_s with
 * @md_n: the amount of bytes to be filled
 * Return: (md_s) a pointer to the memory area md_s
 */
char *md_memset(char *md_s, char md_b, unsigned int md_n)
{
	unsigned int md_i;

	for (md_i = 0; md_i < md_n; md_i++)
		md_s[md_i] = md_b;
	return (md_s);
}

/**
 * md_ffree - frees a string of strings
 * @md_pp: string of strings
 */
void md_ffree(char **md_pp)
{
	char **md_a = md_pp;

	if (!md_pp)
		return;
	while (*md_pp)
		free(*md_pp++);
	free(md_a);
}

/**
 * md_realloc - reallocates a block of memory
 * @md_ptr: pointer to previous malloc'ated block
 * @md_old_size: byte size of previous block
 * @md_new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *md_realloc(void *md_ptr, unsigned int md_old_size, unsigned int md_new_size)
{
	char *md_p;

	if (!md_ptr)
		return (malloc(md_new_size));
	if (!md_new_size)
		return (free(md_ptr), NULL);
	md_old_size = (md_old_size < md_new_size) ? md_old_size : md_new_size;
	if (md_new_size == md_old_size)
		return (md_ptr);

	md_p = malloc(md_new_size);
	if (!md_p)
		return (NULL);

	while (md_old_size--)
		md_p[md_old_size] = ((char *)md_ptr)[md_old_size];
	free(md_ptr);
	return (md_p);
}

