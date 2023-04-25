#include "main.h"

/**
 * _char - a function for printing a character
 * @val: the arguments.
*Return: printed characters.
*/
int _char(va_list val)
{
char a;

a = va_arg(val, int);
_putchar(a);
return (1);
}
