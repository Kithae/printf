#include "main.h"

/**
 * _HEX_aux - another function for printing hexadecimal numbers
 * @num: a number
*Return: the number.
*/
int _HEX_aux(unsigned int num)
{
int x;
int *arr;
int count = 0;
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
arr[x] = arr[x] + 7;
_putchar(arr[x] + '0');
}
free(arr);
return (count);
}
