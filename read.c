#include "main.h"

char *_read(int *fe)
{
	char *string = NULL;
	size_t buffer_size = 0;

	fe = _getline(&input, &buffer_size, stdin);

	return (string);
}
