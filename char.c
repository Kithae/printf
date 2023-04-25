#include "main.h"

/**
 * _char - a function for printing a character
 * @val: the arguments.
*Return: printed characters.
*/
int _char(va_list val)
{
char s;

s = va_arg(val, int);
_putchar(s);
return (1);
}
