#include "palindrome.h"

/**
 * is_palindrome - checck if a number is palindrome
 * @n: the number to check
 * Return: 1 if palidnrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{

	unsigned long reversed = 0, remainder, original;

	original = n;
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 +remainder;
		n /= 10;
	}

	if (original == reversed)
		return (1);

	return (0);
}
