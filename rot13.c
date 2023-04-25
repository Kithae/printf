#include "main.h"
/**
 * _rot13 - a function for printing rot13 strings
 * @args: the arguments
*Return: strings
*/
int _rot13(va_list args)
{
int x, y, count = 0;
int k = 0;
char *s = va_arg(args, char*);
char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

if (s == NULL)
s = "(null)";
for (x = 0; s[x]; x++)
{
k = 0;
for (y = 0; alpha[y] && !k; y++)
{
if (s[x] == alpha[y])
{
_putchar(beta[y]);
count++;
k = 1;
}
}
if (!k)
{
_putchar(s[x]);
count++;
}
}
return (count);
}
