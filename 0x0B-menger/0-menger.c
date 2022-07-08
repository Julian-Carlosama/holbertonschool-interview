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
        int row = 0, col = 0, x = 0, size;

        size = pow(3, level);

        for (; row <= size; row++)
        {
                for (; col <= size; col++)
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