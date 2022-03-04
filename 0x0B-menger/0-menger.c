#include "menger.h"

/**
 * menger - print a menfet function
 *
 * @level: the level of menger sponge
 */
void menger(int level)
{
	int num, row, col, drow, dcol, f;

	num = to_square(level);

	for (col = 0; col < num; col++)
	{
		for (row = 0; row < num; row++)
		{
			dcol = col;
			drow = row;
			f = 0;
			while (dcol && drow)
			{
				if (drow % 3 == 1 && dcol % 3 == 1)
				{
					printf(" ");
					f = 1;
					break;
				}
				drow = drow / 3;
				dcol = dcol / 3;
			}
			if(!f)
			{
				printf("#");
			}
		}
		printf("\n");
	}
}


/**
 * to_square - get the number for a square num by 3
 * @num: the num where how times is going to multiply
 * Return: the obj to the merge sponge
 */
int to_square(int num)
{
	int x = 1, i;

	for (i = 0; i < num; i++)
	{
		x = x * 3;
	}
	return (x);
}
