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

	int word_length = strlen(words[0]);
	int total_length = word_length * nb_words;
	int s_length = strlen(s);

	for (int i = 0; i < s_length - total_length + 1; i++)
	{
		int found_count = 0;
		for (int j = 0; j < nb_words; j++)
		{
			char *p = strstr(s + i + word_length * j, words[j]);

			if (p != NULL && (size_t)(p -s) == (size_t)(i + word_length * j))
				found_count++;

		}
		if (found_count == nb_words)
            		index_arr[count++] = i;
	}
	*n = count;
	return (index_arr);
}
