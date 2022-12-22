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

	for (size_t i = 0; i < strlen(s) - len_words + 1; i++)
	{
		int found_count = 0;
		for (int j = 0; j < nb_words; j++)
		{
			char *p = strstr(s + i, words[j]);
			if (p != NULL)
			{
				found_count++;
				i = p - s;
			}
		}
		if (found_count == nb_words)
            		index_arr[count++] = i - found_count + 1;
	}
	*n = count;
	return (index_arr);
}
