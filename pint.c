#include "monty.h"

/**
 * f_pint - Prints the top element of the stack
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Description: This function prints the top element of the stack.
 * If the stack is empty, it prints an error message and exits the program.
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the Monty file where the operation occurs.
 * Return: No return value.
 */
void f_pint(stack_t **head, unsigned int counter)
{
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		/* Print error message with line number */
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);

		/* Close the file associated with Monty */
		fclose(bus.file);

		/* Free dynamically allocated memory for Monty content */
		free(bus.content);

		/* Free the memory allocated for the stack */
		free_stack(*head); /* Free the memory allocated for the stack */

		exit(EXIT_FAILURE); /* Exit the program with a failure status */
	}

	/* Print the top element of the stack */
	printf("%d\n", (*head)->n);
}

