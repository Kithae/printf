#include "main.h"
/**
 * _exclusive_string - a function for printing special strings.
 * @val: the argument.
*Return: total string length.
*/

int _exclusive_string(va_list val)
{
char *s;
int i, len = 0;
int cast;

s = va_arg(val, char *);
if (s == NULL)
s = "(null)";
for (i = 0; s[i] != '\0'; i++)
{
if (s[i] < 32 || s[i] >= 127)
{
_putchar('\\');
_putchar('x');
len = len + 2;
cast = s[i];
if (cast < 16)
{
_putchar('0');
len++;
}
len = len + _HEX_aux(cast);
}
else
{
_putchar(s[i]);
len++;
}
}
return (len);
}
