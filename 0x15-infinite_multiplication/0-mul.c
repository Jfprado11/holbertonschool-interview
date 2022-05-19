#include "multiplication.h"
/**
 * main- the main function
 *@argc: varible counts
 *@argv: a string
 * Return: a number in success or failed
 */
int main(int argc, char *argv[])
{
	int check_a, check_b;

	if (argc != 3)
	{
		printError();
		exit(98);
	}
	check_a = checkDigit(argv[1]);
	check_b = checkDigit(argv[2]);
	if (check_a == 0 || check_b == 0)
	{
		printError();
		exit(98);
	}
	_putchar(argv[1][0]);
}

/**
 * printError- the main function
 *
 */
void printError(void)
{
	char *error = "Error";
	int i = 0;

	for (; i <= 4; i++)
	{
		_putchar(error[i]);
	}
	_putchar('\n');

}
/**
 * checkDigit- check the digits
 * @strI: the string to compare
 *
 * Return: the diigt 1 true or 0 fasle
 */
int checkDigit(char *strI)
{
	int i;

	for (i = 0; i < _strlen(strI); i++)
	{
		if (strI[i] >= '0' && strI[i] <= '9')
		{
			continue;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
 *_strlen - Tells the length or size of a string
 *@s: varible to test the string
 *
 *Return: len the length of the string
 */
int _strlen(char *s)
{
	int lon = 0;

	while (*s != 0)
	{
		s++;
		lon++;
	}
	return (lon);
}

