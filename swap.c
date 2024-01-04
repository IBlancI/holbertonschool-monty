#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 *
 * Description: This function swaps the top two elements of the stack.
 * If the stack has less than two elements, it prints an error message
 * and exits the program.
 *
 * @head: A pointer to the head of the stack.
 * @counter: The line number in the Monty file where the operation occurs.
 *
 * Return: No return value.
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Count the number of elements in the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if the stack has less than two elements */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head); /* Free the memory allocated for the stack */
		exit(EXIT_FAILURE); /* Exit the program with a failure status */
	}

	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux; /* Swap the values of the top two elements */
}

