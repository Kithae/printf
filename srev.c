#include "main.h"

/**
*_srev - a function for printing reverse strings.
*@args: the arguments
*Return: string.
*/
int _srev(va_list args)
{

char *s = va_arg(args, char*);
int x;
int y = 0;

if (s == NULL)
s = "(null)";
while (s[y] != '\0')
y++;
for (x = y - 1; x >= 0; x--)
_putchar(s[x]);
return (y);
}
