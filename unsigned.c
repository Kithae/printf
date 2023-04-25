#include "main.h"
/**
 * _unsigned - a function for printing integers.
 * @args: the arguments
*Return: printed characters.
*/
int _unsigned(va_list args)
{
unsigned int y = va_arg(args, unsigned int);
int number, last = y % 10, digit, exp = 1;
int x = 1;

y = y / 10;
number = y;

if (last < 0)
{
_putchar('-');
number = -number;
y = -y;
last = -last;
x++;
}
if (number > 0)
{
while (number / 10 != 0)
{
exp = exp * 10;
number = number / 10;
}
number = y;
while (exp > 0)
{
digit = number / exp;
_putchar(digit + '0');
number = number - (digit *exp);
exp = exp / 10;
x++;
}
}
_putchar(last + '0');

return (x);
}
