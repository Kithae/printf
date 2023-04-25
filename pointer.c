#include "main.h"

/**
 * _pointer - a function for printing hexadecimal numbers.
 * @val: the arguments.
*Return: numbers.
*/
int _pointer(va_list val)
{
void *p;
char *s = "(nil)";
long int y;
int z;
int x;

p = va_arg(val, void*);
if (p == NULL)
{
for (x = 0; s[x] != '\0'; x++)
{
_putchar(s[x]);
}
return (x);
}

y = (unsigned long int)p;
_putchar('0');
_putchar('x');
z = _hex_aux(y);
return (z + 2);
}
