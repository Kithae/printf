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
int x = 0, y, len = 0;

va_start(args, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);

Here:
while (format[x] != '\0')
{
y = 13;
while (y >= 0)
{
if (m[y].id[0] == format[x] && m[y].id[1] == format[x + 1])
{
len += m[y].f(args);
x = x + 2;
goto Here;
}
y--;
}
_putchar(format[x]);
len++;
x++;
}
va_end(args);
return (len);
}
