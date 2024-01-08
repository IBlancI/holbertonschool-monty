#include "monty.h"

/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	// Indique que le mode d'exécution est "queue" (file)
	(void)head; // Ignorer le paramètre non utilisé
	(void)counter; // Ignorer le paramètre non utilisé
	bus.lifi = 1; // Modifier le mode d'exécution pour utiliser une file (queue)
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

	aux = *head; // Pointeur auxiliaire pour parcourir la pile

	// Alloue de la mémoire pour un nouveau nœud de pile
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n"); // Affiche une erreur si l'allocation échoue
	}

	// Initialise la valeur du nouveau nœud avec la valeur donnée
	new_node->n = n;
	new_node->next = NULL;

	// Si la pile n'est pas vide, parcourt jusqu'à la fin de la pile
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	// Si la pile est vide, le nouveau nœud devient la tête de la pile
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else // Sinon, ajoute le nouveau nœud à la fin de la pile
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

