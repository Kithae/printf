#include "main.h"

/**
 * _oct - a function for printing octal numbers
 * @val: the arguments.
*Return: numbers.
*/
int _oct(va_list val)
{
int x;
int *arr;
int count = 0;
unsigned int num = va_arg(val, unsigned int);
unsigned int temp = num;

while (num / 8 != 0)
{
num /= 8;
count++;
}
count++;
arr = malloc(count *sizeof(int));

for (x = 0; x < count; x++)
{
arr[x] = temp % 8;
temp /= 8;
}
for (x = count - 1; x >= 0; x--)
{
_putchar(arr[x] + '0');
}
free(arr);
return (count);
}
