#include "monty.h"

/**
 * main - principal function(monty interpreter)
 *
 *@argc: the number of arguments
 *
 *@argv: the arguments
 *
 *Return: 0
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *open;
	char *line = NULL, *tokens = NULL;
	size_t bufsize = 0;
	unsigned int lines = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open = fopen(argv[1], "r");
	if (open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &bufsize, open) != EOF)
	{
		tokens =  strtok(line, DELIMITERS);
		/*if (tokens != NULL && tokens[0] != '#')*/
		if (!tokens)
		{
			lines++;
			free(tokens);
			continue;
		}
		_opcode(tokens, &stack, lines);
		lines++;
	}
	free(line);
	fclose(open);
	if (stack)
		free_stack(stack);
	return (EXIT_SUCCESS);
}
