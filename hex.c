#include "main.h"

/**
 * _hex - a function for printing hexadecimal numbers
 * @val: the arguments.
*Return: numbers.
*/
int _hex(va_list val)
{
int x;
int *arr;
int count = 0;
unsigned int num = va_arg(val, unsigned int);
unsigned int temp = num;

while (num / 16 != 0)
{
num /= 16;
count++;
}
count++;
arr = malloc(count *sizeof(int));

for (x = 0; x < count; x++)
{
arr[x] = temp % 16;
temp /= 16;
}
for (x = count - 1; x >= 0; x--)
{
if (arr[x] > 9)
arr[x] = arr[x] + 39;
_putchar(arr[x] + '0');
}
free(arr);
return (count);
}
