#include "monty.h"

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Takes a string and separates its words.
 *
 * @str: String to separate into word.
 * @delims: Delimitors to use to delimit words.
 *
 * Return: 2D array of pointers to each word.
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wlen, num, index = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (index < wc)
	{
		wlen = get_word_length(str, delims);

		if (is_delim(*str, delims))
			str = get_next_word(str, delims);
		words[index] = malloc((wlen + 1) * sizeof(char));

		if (words[index] == NULL)
		{
			while (index >= 0)
			{
				index--;
				free(words[index]);
			}
			free(words);

			return (NULL);
		}
		num = 0;

		while (num < wlen)
		{
			words[index][num] = *(str + num);
			num++;
		}
		words[index][num] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		index++;
	}
	words[index] = NULL; /* last element is null for iteration */

	return (words);
}

/**
 * is_delim - Checks if stream has delimitor char.
 *
 * @ch: Character in stream.
 * @delims: Pointer to null terminated array of delimitors.
 *
 * Return: 1 (Sucess) 0 (Failure)
 */
int is_delim(char ch, char *delims)
{
	int index = 0;

	while (delims[index])
	{
		if (delims[index] == ch)
			return (1);
		index++;
	}

	return (0);
}

/**
 * get_word_length - Gets the word length of cur word in str.
 *
 * @str: String to get word length from current words.
 * @delims: Delimitors to use to delimit words.
 *
 * Return: Word length of current word.
 */
int get_word_length(char *str, char *delims)
{
	int wlen = 0, pending = 1, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			pending = 1;
		else if (pending)
			wlen++;

		if (wlen > 0 && is_delim(str[index], delims))
			break;
		index++;
	}

	return (wlen);
}

/**
 * get_word_count - Gets the word count of a string.
 *
 * @str: String to get word count from.
 * @delims: Delimitors to use to delimit words.
 *
 * Return: The word count of the string.
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		index++;
	}

	return (wc);
}

/**
 * get_next_word - Gets the next word in a string.
 *
 * @str: String to get next word from.
 * @delims: Delimitors to use to delimit words.
 *
 * Return: Pointer to first char of next word.
 */
char *get_next_word(char *str, char *delims)
{
	int pending = 0, index = 0;

	while (*(str + index))
	{
		if (is_delim(str[index], delims))
			pending = 1;
		else if (pending)
			break;
		index++;
	}

	return (str + index);
}
