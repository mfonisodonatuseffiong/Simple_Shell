#include "main.h"

int _geterror(shell_data data, int error_val)
{
	char *err;

	switch (error_val)
	{
		case -1:
			err = env_error(data);
			break;

		case 2:
			if (string_cmp("exit", data->arguments[0]) == 0)
			{
				err = exit_error(data);
			}
			else if (string_cmp("cd", data->arguments[0]) == 0)
			{
				err = cd_error(data);
			}

			break;

		case 126:
			err = path_error(data);
			break;

		case 127:
			err = notfound_error(data);
			break;
	}

	if (err != NULL)
	{
		write(STRR_FILENO, err, string_len(err));
		free(err);
	}

	data->stat = error_val;

	return (error_val);
}
