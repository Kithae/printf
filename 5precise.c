#include "main.h"

/**
 * get_precision - a function to calculate print precision
 * @format: a string
 * @i: input argument.
 * @list: arguments list.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur_a = *i + 1;
	int precise = -1;

	if (format[cur_a] != '.')
		return (precise);

	precise = 0;

	for (cur_a += 1; format[cur_a] != '\0'; cur_a++)
	{
		if (is_digit(format[cur_a]))
		{
			precise *= 10;
			precise += format[cur_a] - '0';
		}
		else if (format[cur_a] == '*')
		{
			cur_a++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_a - 1;

	return (precise);
}
