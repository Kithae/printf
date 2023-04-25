#include "main.h"

/**
 * _hex_aux  - a function for printing hexadecimal numbers
 * @num: a number
*Return: numbers.
*/
int _hex_aux(unsigned long int num)
{
long int x;
long int *arr;
long int count = 0;
unsigned long int temp = num;

while (num / 16 != 0)
{
num /= 16;
count++;
}
count++;
arr = malloc(count *sizeof(long int));

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
