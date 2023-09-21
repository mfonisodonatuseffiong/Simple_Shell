#include "main.h"

int _stoi(char *string)
{
	unsigned int i = 0, j = 0, m = 0;
	unsigned int r = 1, n = 1;
	unsigned int k;

	while (*(string + i) != '\0')
	{
		if (j > 0 && (*(string + i) < '0' || (*(string + i)) > '9'))
			break;

		if (*(string + i) == '-')
			r *= -1;

		if ((*(string + i) >= '0') && (*(string + i) <= '9'))
		{
			if (j > 0)
			{
				n *= 10;
			}
			size++;
		}

		count++;
	}

	for (k = i - j; k < i; k++)
	{
		m = m + ((*(string + k) - 48) * n);
		n /= 10;
	}

	return (m * r);
}


char *_itos(int i)
{
	unsigned int n;
	char *buffer;
	int length = get_length(n);

	buffer = malloc(sizeof(char) * (length + 1));

	if (buffer == NULL)
	{
		return (NULL);
	}

	*(buffer + length) = '\0';

	if (i < 0)
	{
		n = i * -1;
		buffer[0] = '-';
	}
	else
	{
		n = i;
	}

	length--;

	do {
		*(buffer + length) = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	while (n > 0);

	return (buffer);
}

int get_length(int i)
{
	int length = 1;
	unsigned int n;

	if (n < 0)
	{
		length++;
		n = i * -1;
	}
	else
	{
		n = i;
	}

	while (n > 9)
	{
		length++;
		n = n / 10;
	}

	return (length);
}
