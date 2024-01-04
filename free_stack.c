#include "monty.h"

/**
 * free_stack - Frees a doubly linked list
 * @head: Head of the stack
 *
 * Description: This function frees a doubly linked list starting from the
 * given head.
 *
 * @head: Pointer to the head of the stack (doubly linked list).
 */
void free_stack(stack_t *head)
{
    stack_t *aux;

    aux = head;

    /* Traverse the stack and free each node */
    while (head)
    {
        aux = head->next; /* Save the next node before freeing the current one */
        free(head); /* Free the current node */
        head = aux; /* Move to the next node */
    }
}

