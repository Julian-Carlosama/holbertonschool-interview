#include "menger.h"
/**
 * menger - Function that draws a 2D Menger Sponge
 * 
 * @level: Is the level of the Menger Sponge to draw
 * 
 * Return: No return
 */

void menger(int level)
{
	int row, col, x = 0, size = 1;

	for (row = 0; row < level; row++)
		size *= 3;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			for (x = size / 3; x > 0; x /= 3)
			{
				if ((row % (x * 3)) / x == 1 && (col % (x * 3)) / x == 1)
					break;
			}
			if (x)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
