#include "main.h"
/**
 * _strlen - a function for returning string length
 * @s: a character pointer
*Return: length.
*/
int _strlen(char *s)
{
int x;

for (x = 0; s[x] != 0; x++)
;
return (x);

}
/**
 * _strlenc - a string length function for character pointers
 * @s: a character pointer
*Return: length
*/
int _strlenc(const char *s)
{
int x;

for (x = 0; s[x] != 0; x++)
;
return (x);
}
