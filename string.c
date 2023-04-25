#include "main.h"
/**
 * _string - a function for printing string length
 * @val: the argument.
*Return: string length.
*/

int _string(va_list val)
{
char *s;
int i, len;

s = va_arg(val, char *);
if (s == NULL)
{
s = "(null)";
len = _strlen(s);
for (i = 0; i < len; i++)
_putchar(s[i]);
return (len);
}
else
{
len = _strlen(s);
for (i = 0; i < len; i++)
_putchar(s[i]);
return (len);
}
}
