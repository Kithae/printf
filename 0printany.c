#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - a function that prints per a described output
* @format: a structured format.
* Return: Characters.
*/
int _printf(const char *format, ...)
{
int a, print = 0, chars_printed = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (a = 0; format && format[a] != '\0'; a++)
{
if (format[a] != '%')
{
buffer[buff_ind++] = format[a];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
chars_printed++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &a);
width = get_width(format, &a, list);
precision = get_precision(format, &a, list);
size = get_size(format, &a);
++a;
print = handle_print(format, &a, list, buffer,
flags, width, precision, size);
if (print == -1)
return (-1);
chars_printed += print;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (chars_printed);
}

/**
* print_buffer - prints only if buffer exists
* @buffer: An array
* @buff_ind: an index.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
