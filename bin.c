#include "main.h"

/**
 * _bin - a function for printing binary numbers
 * @val: the arguments.
*Return: the number.
*/
int _bin(va_list val)
{
int flgs = 0;
int count = 0;
int x, y = 1, z;
unsigned int num = va_arg(val, unsigned int);
unsigned int p;

for (x = 0; x < 32; x++)
{
p = ((y << (31 - x)) & num);
if (p >> (31 - x))
flgs = 1;
if (flgs)
{
z = p >> (31 - x);
_putchar(z + 48);
count++;
}
}
if (count == 0)
{
count++;
_putchar('0');
}
return (count);
}
