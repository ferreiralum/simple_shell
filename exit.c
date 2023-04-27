#include "main.h"

/**
 * _strncpy - Copies a string up to n characters.
 *
 * @dest: The destination buffer to copy to.
 * @src: The source buffer to copy from.
 * @n: The maximum number of characters to copy.
 * Author: Ferreira Lumbimi
 * Return: A pointer to the destination buffer.
 */
char *_strncpy(char *dest, char *src, int n)
{
int dest_len = 0, src_len = 0;
char *s = dest;

while (src[src_len] != '\0' && src_len < n - 1)
{
dest[dest_len] = src[src_len];
src_len++;
dest_len++;
}

if (src_len < n)
{
while (dest_len < n)
{
dest[dest_len] = '\0';
dest_len++;
}
}

return (s);
}

/**
 * _strncat - Concatenates two strings up to n characters.
 *
 * @dest: The destination buffer to append to.
 * @src: The source buffer to append from.
 * @n: The maximum number of characters to append.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0, src_len = 0;
char *s = dest;

while (dest[dest_len] != '\0')
dest_len++;

while (src[src_len] != '\0' && src_len < n)
{
dest[dest_len] = src[src_len];
src_len++;
dest_len++;
}

if (src_len < n)
dest[dest_len] = '\0';
return (s);
}

/**
 * _strchr - Finds the first occurrence of a character in a string.
 *
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return: A pointer to the first occurrence of c in s, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return s;
} while (*s++ != '\0');

return NULL;
}

