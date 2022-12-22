#include "substring.h"
#include <string.h>
#include <stdlib.h>

/**
 * find_substring - Finds all the possible substrings containing a list of words.
 * @s: Is the string to scan
 * @words: Is the array of words all substrings must be a concatenation.
 * @nb_words: Is the number of elements in the array words.
 * @n: Holds the address at which to store the number of elements in the returned array.
 * Return:
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int count = 0, len_words = 0;
	int *index_arr = malloc(sizeof(int) * len_words);

	if (!s || !words || nb_words == 0 || !n)
		return (NULL);

	for (int i = 0; i < nb_words; i++)
		len_words += strlen(words[i]);

	if (index_arr == NULL)
		return (NULL);

	for (size_t i = 0; i < strlen(s); i++)
	{
		for (int j = 0; j < nb_words; j++)
			if (s[i] == words[j][0])
			{
				int k = i + 1;
				int l = 1;
				while (s[k] == words[j][l] && s[k] != '\0' && words[j][l] != '\0')
				{
					k++;
					l++;
				}

				if (words[j][l] == '\0')
					index_arr[count++] = i;
			}
	}
	*n = count;
	return (index_arr);
}
