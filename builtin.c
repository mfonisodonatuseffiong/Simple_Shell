#include "shell.h"

/**
 * md_exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info->md_argv[0] != "exit"
 */
int md_exit(info_t *info)
{
	int md_exitcheck;

	if (info->md_argv[1]) /* If there is an exit argument */
	{
		md_exitcheck = md_erratoi(info->md_argv[1]);
		if (md_exitcheck == -1)
		{
			info->md_status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->md_argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->md_err_num = md_erratoi(info->md_argv[1]);
		return (-2);
	}
	info->md_err_num = -1;
	return (-2);
}

/**
 * md_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_cd(info_t *info)
{
	char *md_s, *md_dir, md_buffer[1024];
	int md_chdir_ret;

	md_s = getcwd(md_buffer, 1024);
	if (!md_s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->md_argv[1])
	{
		md_dir = md_getenv(info, "HOME=");
		if (!md_dir)
			md_chdir_ret = /* TODO: what should this be? */
				chdir((md_dir = md_getenv(info, "PWD=")) ? md_dir : "/");
		else
			md_chdir_ret = chdir(md_dir);
	}
	else if (_strcmp(info->md_argv[1], "-") == 0)
	{
		if (!md_getenv(info, "OLDPWD="))
		{
			_puts(md_s);
			_putchar('\n');
			return (1);
		}
		_puts(md_getenv(info, "OLDPWD=")), _putchar('\n');
		md_chdir_ret = /* TODO: what should this be? */
			chdir((md_dir = md_getenv(info, "OLDPWD=")) ? md_dir : "/");
	}
	else
		md_chdir_ret = chdir(info->md_argv[1]);
	if (md_chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->md_argv[1]), _eputchar('\n');
	}
	else
	{
		md_setenv(info, "OLDPWD", md_getenv(info, "PWD="));
		md_setenv(info, "PWD", getcwd(md_buffer, 1024));
	}
	return (0);
}

/**
 * md_help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int md_help(info_t *info)
{
	char **md_arg_array;

	md_arg_array = info->md_argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*md_arg_array); /* temp att_unused workaround */
	return (0);
}

