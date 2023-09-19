#include "shell.h"

/**
 * md_strcpy - copies a string
 * @md_dest: the destination
 * @md_src: the source
 *
 * Return: pointer to destination
 */
char *md_strcpy(char *md_dest, char *md_src)
{
	int md_i = 0;

	if (md_dest == md_src || md_src == 0)
		return (md_dest);

	while (md_src[md_i])
	{
		md_dest[md_i] = md_src[md_i];
		md_i++;
	}
	md_dest[md_i] = 0;
	return (md_dest);
}

/**
 * md_strdup - duplicates a string
 * @md_str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *md_strdup(const char *md_str)
{
	int md_length = 0;
	char *md_ret;

	if (md_str == NULL)
		return (NULL);

	while (*md_str++)
		md_length++;

	md_ret = malloc(sizeof(char) * (md_length + 1));
	if (!md_ret)
		return (NULL);

	for (md_length++; md_length--;)
		md_ret[md_length] = *--md_str;

	return (md_ret);
}

/**
 * md_puts - prints an input string
 * @md_str: the string to be printed
 *
 * Return: Nothing
 */
void md_puts(char *md_str)
{
	int md_i = 0;

	if (!md_str)
		return;

	while (md_str[md_i] != '\0')
	{
		md_putchar(md_str[md_i]);
		md_i++;
	}
}

/**
 * md_putchar - writes the character c to stdout
 * @md_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int md_putchar(char md_c)
{
	static int md_i;
	static char md_buf[WRITE_BUF_SIZE];

	if (md_c == BUF_FLUSH || md_i >= WRITE_BUF_SIZE)
	{
		write(1, md_buf, md_i);
		md_i = 0;
	}

	if (md_c != BUF_FLUSH)
		md_buf[md_i++] = md_c;

	return (1);
}

