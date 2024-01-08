#include "monty.h"

/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	/* Set bus.lifi to 1 */
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
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
}

