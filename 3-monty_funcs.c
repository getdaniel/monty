#include "monty.h"

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void set_op_tok_error(int error_code);

/**
 * monty_stack - Converts a queue to a stack.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @line_number: The current working line number of a monty bytecode files.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @line_number: The current working line number of a monty bytecode files.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

/**
 * set_op_tok_error - Sets last element of set_op_toks to be an error code.
 *
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
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
