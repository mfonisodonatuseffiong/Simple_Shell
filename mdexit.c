/**
 * md_exit - exits the shell with a status
 * @md_args: the arguments passed to the function
 *
 * Return: Always 0
 */
int md_exit(char **md_args)
{
	int md_status = 0;

	if (md_args && md_args[1])
	{
		md_status = _atoi(md_args[1]);
		if (md_status == -1)
		{
			md_print("Illegal number: ");
			md_print(md_args[1]);
			md_print("\n");
			return (2);
		}
	}
	free(md_args);
	exit(md_status); /* Exiting the shell with the specified status */
	return (md_status);
}

