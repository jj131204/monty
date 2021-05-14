#include "monty.h"

/**
 * _sub - Subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *res_node = *stack;
	int sub = 0;

	if (!stack || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	else
	{
		sub += (*stack)->next->n - (*stack)->n;
		(*stack)->next->n = sub;
		*stack = (*stack)->next;
		free(res_node);
	}

}
