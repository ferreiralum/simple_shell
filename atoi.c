#include "main.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: pointer to info_t struct
 * Author: Ferreira Lumbimi
 * Return: 1 if shell is in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return isatty(STDIN_FILENO) && info->readfd <= 2;
}

/**
 * is_delim - checks if character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 *
 * Return: 1 if character is a delimiter, 0 otherwise
 */
int is_delim(char c, const char *delim)
{
while(*delim)
{
if(*delim++ == c)
return 1;
}
return 0;
}

/**
 * _isalpha - checks for alphabetic character
 * @c: character to check
 *
 * Return: 1 if character is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
int i, sign = 1, output = 0;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == '-')
sign *= -1;
else if (_isdigit(s[i]))
output = output * 10 + (s[i] - '0');
else if (output > 0)
break;
}

return (output * sign);
}
