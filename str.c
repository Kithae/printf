#include "main.h"
/**
 * _strlen - a function for returning string length
 * @s: a character pointer
*Return: length.
*/
int _strlen(char *s)
{
int c;

for (c = 0; s[c] != 0; c++)
;
return (c);

}
/**
 * _strlenc - a string length function for character pointers
 * @s: a character pointer
*Return: length
*/
int _strlenc(const char *s)
{
int c;

for (c = 0; s[c] != 0; c++)
;
return (c);
}
