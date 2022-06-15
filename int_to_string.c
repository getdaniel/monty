#include "monty.h"

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff,
		int buff_size);

/**
 * get_int - Gets a character to new string containing int.
 *
 * @num: Number to convert to string.
 *
 * Return: Character pointer to newly created string.
 *         NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int tmp;
	int length = 0;
	long num_l = 0;
	char *ret;

	tmp = _abs(num);
	length = get_numbase_len(tmp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);
	fill_numbase_buff(tmp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Gets the absolute value of an integer.
 *
 * @index: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of index.
 */
unsigned int _abs(int index)
{
	if (index < 0)
		return (-(unsigned int)index);

	return ((unsigned int)index);
}

/**
 * get_numbase_len - Gets length of buffer needed for an unsigned int.
 *
 * @num: Number to get length needed for.
 * @base: Base of number representation used by buffer.
 *
 * Return: Integer containing length of buffer needed(doesn't contain nul bit).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain at least one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}

	return (len);
}

/**
 * fill_numbase_buff - Fills buffer with correct numbers up to base 36.
 *
 * @num: Numbers to convert to string given base.
 * @base: Base of  number used in conversion, only works up to base 36.
 * @buff: buffer to fill with result of conversion.
 * @buff_size: Size of buffer in bytes.
 */
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff,
		int buff_size)
{
	int rem, index = buff_size - 1;

	buff[buff_size] = '\0';

	while (index >= 0)
	{
		rem = num % base;

		if (rem > 9) /* return lowercase ascii val representation */
			buff[index] = rem + 87; /* 10 will be a 11 = b ... */
		else
			buff[index] = rem + '0';
		num /= base;
		index--;
	}
}
