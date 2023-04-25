#include "main.h"

/**
 * _putchar - a function that writes characters to standard output
 * @c: The character in reference
*Return: 1, else error.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
