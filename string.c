#include "main.h"
/**
 * _string - a function for printing string length.
 * @val: the argument
*Return: string length.
*/

int _string(va_list val)
{
char *a;
int x, length;

a = va_arg(val, char *);
if (a == NULL)
{
a = "(null)";
length = _strlen(a);
for (x = 0; x < length; x++)
_putchar(a[x]);
return (length);
}
else
{
length = _strlen(a);
for (x = 0; x < length; x++)
_putchar(a[x]);
return (length);
}
}
