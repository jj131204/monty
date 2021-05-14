#include "monty.h"

/**
 * _push - This function pushes an element to the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_num: Number of the line.
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_num)
{
	char *value = strtok(NULL, DELIMITERS);
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(2);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	new_node->n = n;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
