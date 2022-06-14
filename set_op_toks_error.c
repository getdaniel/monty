#include "monty.h"

/**
 * set_op_toks_error - Sets last element of set_op_toks to be an error code.
 *
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_toks_error(int error_code)
{
	int toks_len = 0, index = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));

	if (!op_toks)
	{
		malloc_error();

		return;
	}

	while (index < toks_len)
	{
		new_toks[index] = op_toks[index];
		index++;
	}
	exit_str = get_int(error_code);

	if (!exit_str)
	{
		free(new_toks);
		malloc_error();

		return;
	}
	new_toks[index++] = exit_str;
	new_toks[index] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
