#include "monty.h"

int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - Prints pop error messages for empty stacks.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: EXIT_FAILURE (Always).
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: EXIT_FAILURE (Always).
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty math function error messages
 *                     for stack//queues smaller than two nodes.
 *
 * @line_number: Line number in script where error occurred.
 * @op: Operations where error occurred.
 *
 * Return: EXIT_FAILURE (Always).
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);

	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: EXIT_FAILURE (Always).
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 *
 * @line_number: Line number in script where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: EXIT_FAILURE (Always).
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);

	return (EXIT_FAILURE);
}
