#include "main.h"

/* TO PRINT A CHARACTER*/
/**
* print_char - a function that prints a character
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed chars
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char y = va_arg(types, int);

return (handle_write_char(y, buffer, flags, width, precision, size));
}
/* TO PRINT A STRING*/
/**
* print_string - a function that prints string
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed string
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, a;
char *string = va_arg(types, char *);

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
{
string = "(null)";
if (precision >= 6)
string = "      ";
}

while (string[length] != '\0')
length++;

if (precision >= 0 && precision < length)
length = precision;

if (width > length)
{
if (flags & F_MINUS)
{
write(1, &string[0], length);
for (a = width - length; a > 0; a--)
write(1, " ", 1);
return (width);
}
else
{
for (a = width - length; a > 0; a--)
write(1, " ", 1);
write(1, &string[0], length);
return (width);
}
}

return (write(1, string, length));
}
/* TO PRINT A % SIGN*/
/**
* print_percent - a function that prints the sign - percent
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed sign
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}

/* TO PRINT AN INTEGER NUMBER*/
/**
* print_int - print int
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed int
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
int is_negative = 0;
long int y = va_arg(types, long int);
unsigned long int num;

y = convert_size_number(y, size);

if (y == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)y;

if (y < 0)
{
num = (unsigned long int)((-1) * y);
is_negative = 1;
}

while (num > 0)
{
buffer[a--] = (num % 10) + '0';
num /= 10;
}

a++;

return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/* TO PRINT A BINARY NUMBER*/
/**
* print_binary - prints unsigned (binary) number
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed binary
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int x, y, g, sum;
unsigned int f[32];
int count;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

x = va_arg(types, unsigned int);
y = 2147483648; /* (2 ^ 31) */
f[0] = x / y;
for (g = 1; g < 32; g++)
{
y /= 2;
f[g] = (x / y) % 2;
}
for (g = 0, sum = 0, count = 0; g < 32; g++)
{
sum += f[g];
if (sum || g == 31)
{
char a = '0' + f[g];

write(1, &a, 1);
count++;
}
}
return (count);
}
