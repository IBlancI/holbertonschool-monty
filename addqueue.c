#include "monty.h"

/**
 * f_queue - Changes the mode of execution to queue (FIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void f_queue(stack_t **head, unsigned int counter)
{
<<<<<<< HEAD
    /* Change the mode of execution to queue (FIFO) */
    (void)head; /* Ignoring the unused parameter */
    (void)counter; /* Ignoring the unused parameter */
    bus.lifi = 1; /* Setting the mode of execution to use a queue */
=======
	(void)head;
	(void)counter;
	/* Set bus.lifi to 1 */
	bus.lifi = 1;
>>>>>>> ba95f577ea6a588669db21d9fef3845da07c06d9
}

/**
 * addqueue - Adds a node to the tail of the stack (queue)
 * @n: New value to be added
 * @head: Pointer to the head of the stack
 * Return: No return value
 */
void addqueue(stack_t **head, int n)
{
<<<<<<< HEAD
    stack_t *new_node, *aux;

    aux = *head; /* Auxiliary pointer to traverse the stack */

    /* Allocate memory for a new stack node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n"); /* Print an error if allocation fails */
    }

    /* Initialize the value of the new node with the given value */
    new_node->n = n;
    new_node->next = NULL;

    /* If the stack is not empty, traverse to the end of the stack */
    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }

    /* If the stack is empty, the new node becomes the head of the stack */
    if (!aux)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else /* Otherwise, add the new node to the end of the stack */
    {
        aux->next = new_node;
        new_node->prev = aux;
    }
=======
	stack_t *new_node, *aux;

	aux = *head;
	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	/* Assign value to the new node */
	new_node->n = n;
	new_node->next = NULL;

	if (aux)
	{
		/* Traverse to the end of the stack */
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		/* If the stack is empty, set the new node as the head */
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Add the new node to the end of the stack */
		aux->next = new_node;
		new_node->prev = aux;
	}
>>>>>>> ba95f577ea6a588669db21d9fef3845da07c06d9
}

