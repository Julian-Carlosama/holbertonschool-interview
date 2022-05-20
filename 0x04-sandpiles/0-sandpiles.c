#include "sandpiles.h"

/**
 *
 */
void _print_grid(int grid[3][3])
{
	int i, j, limit = 3;

	for (i = 0; i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * 
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, limit = 3;

	for (i = 0; i < limit; i++)
		for (j = 0; j < limit; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 *
 */
int is_stable(int grid[3][3])
{
	int i, j, limit = 3;

	for (i = 0; i < limit; i++)
		for (j = 0; j < limit; j++)
			if (grid[i][j] > limit)
				return (0);

	return (1);
}

/**
 * 
 */
void toppling(int grid[3][3])
{
	int i, j, limit = 3, wall = 2;

	int grid_tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < limit; i++)
	{
		for (j = 0; j < limit; j++)
		{
			if (grid[i][j] > limit)
			{
				(i - 1) >= 0 ? grid_tmp[i - 1][j]++ : 0;

				(i + 1) <= wall ? grid_tmp[i + 1][j]++ : 0;

				(j - 1) >= 0 ? grid_tmp[i][j - 1]++ : 0;

				(j + 1) <= wall ? grid_tmp[i][j + 1]++ : 0;

				grid[i][j] -= 4;
			}
		}
	}

	grid_sum(grid, grid_tmp);
}

/**
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		_print_grid(grid1);
		toppling(grid1);
	}
}