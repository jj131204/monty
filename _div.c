#include "monty.h"

/**
 * _div -  divides the second top element of the stack
 *		by the top element of the stack.
 *
 *@stack: Double pointer to the head of the Stack.
 *
 * @line_number: Number of the line.
 *
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *div_node = *stack;
	int div = 0;

	if (!stack || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	div += (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	*stack = (*stack)->next;
	free(div_node);

}
