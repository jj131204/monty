#include "monty.h"

/**
 *_pop - function that removes the top element of the stack.
 *
 *@stack:  Double pointer to the head of the Stack
 *
 *@line_number:  number of the line
 */


void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	*stack = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
	}
	free(tmp);
}
