#include "shell.h"

/**
 * md_main - Entry point
 * @md_ac: Argument count
 * @md_av: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int md_main(int md_ac, char **md_av)
{
	info_t md_info = INFO_INIT;
	int md_fd = 2;

	asm (
		"mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (md_fd)
		: "r" (md_fd)
	);

	if (md_ac == 2)
	{
		md_fd = open(md_av[1], O_RDONLY);
		if (md_fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(md_av[0]);
				_eputs(": 0: Can't open ");
				_eputs(md_av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		md_info.readfd = md_fd;
	}
	populate_env_list(&md_info);
	read_history(&md_info);
	hsh(&md_info, md_av);
	return (EXIT_SUCCESS);
}

