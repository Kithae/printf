#include "main.h"

/*TO PRINT A NUMBER (UNSIGNED)*/
/**
* print_unsigned - a function that prints unsigned number
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed number
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[a--] = (number % 10) + '0';
number /= 10;
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/*TO PRINT A NUMBER IN OCTAL (UNSIGNED)*/
/**
* print_octal - a function that prints in the octal notation
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed number
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int init_number = number;

UNUSED(width);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[a--] = (number % 8) + '0';
number /= 8;
}

if (flags & F_HASH && init_number != 0)
buffer[a--] = '0';

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/*TO PRINT A NUMBER IN HEXADECIMAL (UNSIGNED)*/
/**
* print_hexadecimal - a function that prints in a hexadecimal notation
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed number
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/*TO PRINT A NUMBER IN UPPER HEXADECIMAL (UNSIGNED)*/
/**
* print_hexa_upper - a function that prints in hexadec notation (upper)
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed number
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/*TO PRINT A NUMBER IN BOTH UPPER OR LOWER HEXADECIMAL*/
/**
* print_hexa - a function that prints in lower or upper hexadec
* @types: arguments list
* @buffer: an array
* @map_to: An array
* @flags:  active flags calculator
* @flag_ch: active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed number
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int init_number = number;

UNUSED(width);

number = convert_size_unsgnd(number, size);

if (number == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (number > 0)
{
buffer[a--] = map_to[number % 16];
number /= 16;
}

if (flags & F_HASH && init_number != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
