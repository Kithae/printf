#include "main.h"

/*TO PRINT A POINTER*/
/**
* print_pointer - a function that prints a pointer's value
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed pointer
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int x = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_address;
char map_to[] = "0123456789abcdef";
void *address = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (address == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_address = (unsigned long)address;

while (num_address > 0)
{
buffer[x--] = map_to[num_address % 16];
num_address /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;

x++;

return (write_pointer(buffer, x, length,
width, flags, padd, extra_c, padd_start));
}

/*TO PRINT NON-PRINTABLE CHARACTERS*/
/**
* print_non_printable - a function that prints hexadecimal ascii codes
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed chars
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = 0, off = 0;
char *string = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (string == NULL)
return (write(1, "(null)", 6));

while (string[a] != '\0')
{
if (is_printable(string[a]))
buffer[a + off] = string[a];
else
off += append_hexa_code(string[a], buffer, a + off);

a++;
}

buffer[a + off] = '\0';

return (write(1, buffer, a + off));
}

/*TO PRINT A STRING IN REVERSE*/
/**
* print_reverse - a function that prints a string in reverse
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed string
*/

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *string;
int a, sum = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

string = va_arg(types, char *);

if (string == NULL)
{
UNUSED(precision);

string = ")Null(";
}
for (a = 0; string[a]; a++)
;

for (a = a - 1; a >= 0; a--)
{
char z = string[a];

write(1, &z, 1);
sum++;
}
return (sum);
}
/*TO PRINT IN ROT13*/
/**
* print_rot13string - a function that prints in rot13
* @types: arguments list
* @buffer: an array
* @flags:  active flags calculator
* @width: a dimension
* @precision: a specifier
* @size: another specifier
* Return: printed string
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *string;
unsigned int a, b;
int sum = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

string = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (string == NULL)
string = "(AHYY)";
for (a = 0; string[a]; a++)
{
for (b = 0; in[b]; b++)
{
if (in[b] == string[a])
{
x = out[b];
write(1, &x, 1);
sum++;
break;
}
}
if (!in[b])
{
x = string[a];
write(1, &x, 1);
sum++;
}
}
return (sum);
}
