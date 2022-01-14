#include "sandpiles.h"

/**
 *sandpiles_sum - sum of sandpiles
 *@grid1: first grid
 *@grid2: second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, end_process = 1, end_all = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (end_process == 1)
	{
		end_process = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4)
				{
					if (i == 0 && j == 0)
					{
						grid1[0][1] += 1;
						grid1[1][0] += 1;
						grid1[0][0] -= 4;
						end_process = 1;
					}
					if (i == 0 && j == 1)
					{
						grid1[0][0] += 1;
						grid1[0][2] += 1;
						grid1[1][1] += 1;
						grid1[0][1] -= 4;
						end_process = 1;
					}
					if (i == 0 && j == 2)
					{
						grid1[0][1] += 1;
						grid1[1][2] += 1;
						grid1[0][2] -= 4;
						end_process = 1;
					}
					if (i == 1 && j == 0)
					{
						grid1[0][0] += 1;
						grid1[1][1] += 1;
						grid1[2][0] += 1;
						grid1[1][0] -= 4;
						end_process = 1;
					}
					if (i == 1 && j == 1)
					{
						grid1[0][1] += 1;
						grid1[1][0] += 1;
						grid1[1][2] += 1;
						grid1[2][1] += 1;
						grid1[1][1] -= 4;
						end_process = 1;
					}
					if (i == 1 && j == 2)
					{
						grid1[0][2] += 1;
						grid1[1][1] += 1;
						grid1[2][2] += 1;
						grid1[1][2] -= 4;
						end_process = 1;
					}
					if (i == 2 && j == 0)
					{
						grid1[1][0] += 1;
						grid1[2][1] += 1;
						grid1[2][0] -= 4;
						end_process = 1;
					}
					if (i == 2 && j == 1)
					{
						grid1[2][0] += 1;
						grid1[1][1] += 1;
						grid1[2][2] += 1;
						grid1[2][1] -= 4;
						end_process = 1;
					}
					if (i == 2 && j == 2)
					{
						grid1[1][2] += 1;
						grid1[2][1] += 1;
						grid1[2][2] -= 4;
						end_process = 1;
					}
				}
			}
		}
		if (end_process == 1 && end_all == 1)
		{
			printf("=\n");
			print_grid_topple(grid1);
		}
	}
}


/**
 * print_grid_topple - to print the grid
 * @grid: the grid to print
 */

void print_grid_topple(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}