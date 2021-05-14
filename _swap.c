#include "monty.h"

/**
 * _swap -  swaps the top two elements of the stack.
 *
 *@stack:  Double pointer to the head of the Stack.
 *
 *@line_number:  Number of the line.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int _stack = 0;
	stack_t *tmp = *stack;

	if (!stack || (*stack)->next == NULL || !(*stack))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	_stack = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = _stack;

}
