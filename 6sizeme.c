#include "main.h"

/**
 * get_size - a function that calculates argument size
 * @format: a string
 * @i: input argument.
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int cur_a = *i + 1;
	int sizeTrue = 0;

	if (format[cur_a] == 'l')
		sizeTrue = S_LONG;
	else if (format[cur_a] == 'h')
		sizeTrue = S_SHORT;

	if (sizeTrue == 0)
		*i = cur_a - 1;
	else
		*i = cur_a;

	return (sizeTrue);
}
