#include "monty.h"

/**
 * f_pall - Prints the elements of the stack
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter (added to match function pointer signature)
 * Description: This function prints the elements of the stack.
 * It traverses the stack and prints each element on a new line.
 * @head: A pointer to the head of the stack.
 * @counter: An unused parameter (added to match function pointer signature).
 * Return: No return value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	/* Set a temporary pointer to the head of the stack */
	stack_t *h;
	(void)counter; /* Unused parameter */

	h = *head; /* Set a temporary pointer to the head of the stack */
	if (h == NULL)
		return; /* If the stack is empty, do nothing */

	/* Traverse the stack and print each element */
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

