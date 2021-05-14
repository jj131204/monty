#include "monty.h"

/**
 *_add - sum the top two elements of the stack.
 *
 *@stack: Double pointer to the head of the Stack
 *
 *@line_number: number of the line
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *sum_node = *stack;
	int add = 0;

	if (!stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		add += (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = add;
		*stack = (*stack)->next;
		free(sum_node);
	}
}
