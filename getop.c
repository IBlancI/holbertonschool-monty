#include "monty.h"

/**
 * get_op_func - Finds and executes the appropriate function based on the opcode
 * @line: Name of the instruction opcode
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int get_op_func(char *line, stack_t **stack, unsigned int line_number)
{
	/* Array of opcode-function pairs */
	instruction_t func[] = {
		{"pall", __pall},
		{"nop", __nop},
		{"pint", __pint},
		{"pop", __pop},
		{"add", __add},
		{"swap", __swap},
		{NULL, NULL},
	};

	int i;

	/* Loop through the array to find the matching opcode */
	for (i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(line, func[i].opcode) == 0)
		{
			/* Execute the corresponding function for the opcode */
			func[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}

	/* Print an error message for unknown instructions */
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);

	/* Set the error flag to indicate failure */
	error = 1;
	return (EXIT_FAILURE);
}

