#include "main.h"
/**
 * _exclusive_string - a function for printing special strings.
 * @val: the argument.
*Return: total string length.
*/

int _exclusive_string(va_list val)
{
char *strs;
int x, length = 0;
int ct;

strs = va_arg(val, char *);
if (strs == NULL)
strs = "(null)";
for (x = 0; strs[x] != '\0'; x++)
{
if (strs[x] < 32 || strs[x] >= 127)
{
_putchar('\\');
_putchar('x');
length = length + 2;
ct = strs[x];
if (ct < 16)
{
_putchar('0');
length++;
}
length = length + _HEX_aux(ct);
}
else
{
_putchar(strs[x]);
length++;
}
}
return (length);
}
