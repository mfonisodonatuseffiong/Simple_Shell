#include "main.h"

ssize_t _getline(char **ptr, size_t *size, FILE *stream)
{
	ssize_t ret;
	static ssize_t input;
	char *buff;
	char c = 'z';
	int i;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	
	input = 0;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	
	if (buff == 0)
		return (-1);
	
	while (c != '\n')
	{
		i = read(STDIN_FILENO, &c, 1);

		if (i == -1 || (i == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buff = _realloc(buff, input, input + 1);
		
		buff[input] = c;
		input++;
	}
	
	buff[input] = '\0';
	_bringline(ptr, size, buff, input);
	ret = input;
	
	if (i != 0)
		input = 0;

	return (ret);
}



void _bringline(char **ptr, size_t *size, char *buff, size_t n)
{
	if (*ptr == NULL)
	{
		if  (n > BUFF_SIZE)
			*size = n;

		else
			*size = BUFF_SIZE;
		*ptr = buff;
	}
	else if (*size < n)
	{
		if (n > BUFF_SIZE)
			*size = n;
		else
			*size = BUFF_SIZE;
		*ptr = buff;
	}
	else
	{
		string_cpy(*ptr, buff);
		free(buff);
	}
}
