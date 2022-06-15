#include "palindrome.h"

/**
 * is_palindrome - Function that checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: The number to check
 * Return: 1 if n is palindrome 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char num[50];
	int i, total_digits;

	/* The number n in array */
	for (i = 0; n; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
	num[i] = '\0';

	total_digits = i;
	for (i = 0; i < (total_digits / 2); i++)
		/* If borders are diferent, then no palindrome */
		if (num[i] != num[total_digits - 1 - i])
			return (0);

	return (1);
}
