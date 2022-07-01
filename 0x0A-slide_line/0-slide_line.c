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

        	while (left < line)
        	{
            		while (*left == 0 && left < line)
            		{
                		left++;
            		}
            		right = left++;
            		while (right < line + size)
            		{
                		if (*right == *left)
                		{
                    			*point_to_next = *left;
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
        	if (*line && !*point_to_next)
        	{
        		*point_to_next = *line;
        		*line = 0;
        	}
	}
	return (1);
}
