#include "monty.h"


/**
 * _opcode - Function for select de parameters (spacifiers)
 *
 *@line: Entry parameter.
 *
 *@stack: Double pointer to the head of the Stack.
 *
 *@lines_num: number of the line
 *
 *Return: exit_success
 */

int _opcode(char *line, stack_t **stack, unsigned int lines_num)
{
	unsigned int count = 0;

	instruction_t specifiers[] = {
		{"pall", _pall},
		{"push", _push},
		{"pint", _pint},
		{"pop",  _pop},
		{"swap", _swap},
		{"add",  _add},
		{"nop",  _nop},
		{"sub",  _sub},
		{"div",  _div},
		{"mull", _mul},
		{NULL, NULL}
	};

	while (count < 9)
	{
		if (strcmp(specifiers[count].opcode, line) == 0)
		{
			specifiers[count].f(stack, lines_num);
			return (EXIT_SUCCESS);
		}
		count++;
	}

	if (!specifiers[count].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", lines_num, line);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
