/**
 * md_eputs - prints an input string
 * @md_str: the string to be printed
 *
 * Return: Nothing
 */
void md_eputs(char *md_str)
{
	int md_i = 0;

	if (!md_str)
		return;
	while (md_str[md_i] != '\0')
	{
		md_eputchar(md_str[md_i]);
		md_i++;
	}
}

/**
 * md_eputchar - writes the character c to stderr
 * @md_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int md_eputchar(char md_c)
{
	static int md_i;
	static char md_buf[WRITE_BUF_SIZE];

	if (md_c == BUF_FLUSH || md_i >= WRITE_BUF_SIZE)
	{
		write(2, md_buf, md_i);
		md_i = 0;
	}
	if (md_c != BUF_FLUSH)
		md_buf[md_i++] = md_c;
	return (1);
}

/**
 * md_putfd - writes the character c to given fd
 * @md_c: The character to print
 * @md_fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int md_putfd(char md_c, int md_fd)
{
	static int md_i;
	static char md_buf[WRITE_BUF_SIZE];

	if (md_c == BUF_FLUSH || md_i >= WRITE_BUF_SIZE)
	{
		write(md_fd, md_buf, md_i);
		md_i = 0;
	}
	if (md_c != BUF_FLUSH)
		md_buf[md_i++] = md_c;
	return (1);
}

/**
 * md_putsfd - prints an input string
 * @md_str: the string to be printed
 * @md_fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int md_putsfd(char *md_str, int md_fd)
{
	int md_i = 0;

	if (!md_str)
		return (0);
	while (*md_str)
	{
		md_i += md_putfd(*md_str++, md_fd);
	}
	return (md_i);
}

