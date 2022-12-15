#include "regex.h"
#include <stdio.h>

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: Ptr to string to check
 * @pattern: Pattern to compare with
 *
 * Return: 1 if match, otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
	int ptr = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);

	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));

	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			ptr = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || ptr);
	}
	return (0);
}
