#include "slide_line.h"


/**
 * slide_line - Slide that merge a line between left or right
 * @line: Input.
 * @size: Array size.
 * @direction: Direction to slide.
 * Return: 1 upon success or 0 upon failure.
 */

int slide_line(int *line, size_t size, int direction)
{
	int *left = NULL;
	int *right = NULL;

	if (direction == 0)
    	{
        	int *point_to_next = NULL;

        	point_to_next = line;
        	left = point_to_next;

        	while (left < line + (size - 1))
        	{
            		while (*left == 0 && left < line + (size - 1))
            		{
                		left++;
            		}
            		right = left + 1;
            		while (right < line + size)
            		{
                		if (*right == *left)
                		{
                    			*point_to_next = *left * 2;
                    			if (point_to_next != left)
                    			{
                    				*left = 0;
                    			}
                    			*right = 0;
                    			point_to_next++;
                    			break;
                		}
                		else
                		{
                    			right++;
                		}
            		}
            		left++;
        	}
        	if (*(line + size - 1) && !*point_to_next)
        	{
        		*point_to_next = *(line + size -1);
        		*(line + size - 1) = 0;
        	}
	}
	return (1);
}
