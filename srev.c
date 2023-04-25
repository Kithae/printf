#include "main.h"

/**
*_srev - a function for printing reverse strings
*@args: the arguments
*Return: string
*/
int _srev(va_list args)
{

char *s = va_arg(args, char*);
int i;
int j = 0;

if (s == NULL)
s = "(null)";
while (s[j] != '\0')
j++;
for (i = j - 1; i >= 0; i--)
_putchar(s[i]);
return (j);
}
