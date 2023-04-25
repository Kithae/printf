#include "main.h"

/**
 * get_width - a function that determines printing width
 * @format: a string
 * @i: input argument.
 * @list: arguments list.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur_a;
	int widthTrue = 0;

	for (cur_a = *i + 1; format[cur_a] != '\0'; cur_a++)
	{
		if (is_digit(format[cur_a]))
		{
			widthTrue *= 10;
			widthTrue += format[cur_a] - '0';
		}
		else if (format[cur_a] == '*')
		{
			cur_a++;
			widthTrue = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_a - 1;

	return (widthTrue);
}
