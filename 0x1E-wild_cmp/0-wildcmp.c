#include "holberton.h"

/**
 * wildcmp - a function to check if a string is valid
 * @s1: the first string to compare
 * @s2: the second string to compare and has the wildcare
 * Return: 1 if is true 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{


	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
	}

	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);

	if (*s2 == *s1)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	return (0);
}
