#include "regex.h"
#include <stdio.h>
/**
 * regex_match - a funtion that check if a string is correct match for Regex
 * @str: the string to compare
 * @pattern: the string with the pattern to compare
 * Return: 1 if the pattern matches the string, or 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	do {
		if (match_here(pattern, str))
			return (1);
	} while (*(str)++ != '\0');

	return (0);
}

/**
 * match_here - check all the conditionsas
 *
 * @regexp: the regex to search
 * @text: the string to seacth the pattern
 * Return: 1 if good or 0 otherwise
 */
int match_here(char const *regexp, char const *text)
{

	if (regexp[0] == '\0' && *text != '\0')
		return (0);

	if (regexp[0] == '\0' && *text == '\0')
		return (1);

	if (regexp[1] == '*')
		return (matchstar(regexp[0], regexp + 2, text));

	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return (match_here(regexp + 1, text + 1));

	return (0);
}

/**
 * matchstar - the check of the start
 *
 * @c: the postion of the caracther
 * @regexp: the pattern to check
 * @text: the text to check
 * Return: if the * is valid
 */
int matchstar(int c, char const *regexp, char const *text)
{
	do {
		if (match_here(regexp, text))
			return (1);
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return (0);
}
