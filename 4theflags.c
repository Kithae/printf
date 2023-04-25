#include "main.h"

/**
* get_flags - a function that cumulates flags
* @format: a string
* @i: the input parameter.
* Return: Flag count
*/
int get_flags(const char *format, int *i)
{
int a, cur_i;
int flagsum = 0;
const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
{
for (a = 0; FLAGS_CHAR[a] != '\0'; a++)
if (format[cur_i] == FLAGS_CHAR[a])
{
flagsum |= FLAGS_ARRAY[a];
break;
}

if (FLAGS_CHAR[a] == 0)
break;
}

*i = cur_i - 1;

return (flagsum);
}
