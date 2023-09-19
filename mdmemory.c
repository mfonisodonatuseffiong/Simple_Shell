#include "shell.h"

/**
 * md_bfree - frees a pointer and sets it to NULL
 * @md_ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int md_bfree(void **md_ptr)
{
	if (md_ptr && *md_ptr)
	{
		free(*md_ptr);
		*md_ptr = NULL;
		return (1);
	}
	return (0);
}

