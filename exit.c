#include "main.h"

int _exit(shell_data *data)
{
	int digit;
	int num;
	int length;
	unsigned int status;

	if (data->arguments[1] != NULL)
	{
		status = _stoi(data->arguments[1]);
		digit = is_digit(data->arguments[1]);
		length = string_len(data->arguments[1]);
		num = status > (unsigned int) INT_MAX;

		if (!digit || length > 10 || num)
		{
			_geterror(data, 2);
			data->stat = 2;
			return (1);
		}

		data->stat = (status % 256);
	}

	return (0);
}
