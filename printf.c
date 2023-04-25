#include "main.h"
/**
*_printf - A function for selecting the right printable function.
*@format: an identifier.
*Return: string length.
*/
int _printf(const char * const format, ...)
{
convert_match m[] = {
{"%s", _string}, {"%c", _char},
{"%%", _37},
{"%i", _int}, {"%d", _dec}, {"%r", _srev},
{"%R", _rot13}, {"%b", _bin}, {"%u", _unsigned},
{"%o", _oct}, {"%x", _hex}, {"%X", _HEX},
{"%S", _exclusive_string}, {"%p", _pointer}
};

va_list args;
int i = 0, j, len = 0;

va_start(args, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);

Here:
while (format[i] != '\0')
{
j = 13;
while (j >= 0)
{
if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
{
len += m[j].f(args);
i = i + 2;
goto Here;
}
j--;
}
_putchar(format[i]);
len++;
i++;
}
va_end(args);
return (len);
}
