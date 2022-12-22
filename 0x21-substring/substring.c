#include "substring.h"
#include <string.h>
#include <stdlib.h>

/**
 * find_substring - Finds all the possible substrings
 * containing a list of words.
 * @s: Is the string to scan.
 * @words: Is the array of words all substrings must be a concatenation.
 * @nb_words: Is the number of elements in the array words.
 * @n: Holds the address at which to store the number of elements
 * in the returned array.
 * Return:
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || nb_words == 0 || !n)
		return (NULL);
	
	int count = 0, len_words = 0;

	for (int i = 0; i < nb_words; i++)
		len_words += strlen(words[i]);

	int *index_arr = malloc(sizeof(int) * len_words);

	if (index_arr == NULL)
		return (NULL);

	char *concat_words = malloc(sizeof(char) * len_words + 1);

	if (concat_words == NULL)
    	{
        	free(index_arr);
        	return (NULL);
    	}

	strcpy(concat_words, words[0]);
	for (int i = 1; i < nb_words; i++)
        	strcat(concat_words, words[i]);

	for (size_t i = 0; i < strlen(s) - len_words + 1; i++)
	{
		if (strncmp(s + i, concat_words, len_words) == 0)
            		index_arr[count++] = i;
		
	}
	*n = count;
	return (index_arr);
}
