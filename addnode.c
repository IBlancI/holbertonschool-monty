#include "monty.h"

/**
 * addnode - ajoute un nœud en tête de pile
 * @head: pointeur vers le sommet de la pile
 * @n: nouvelle valeur à ajouter
 * Return: pas de retour
 */
void addnode(stack_t **head, int n)
{
	 /* Déclaration de pointeurs de type stack_t */
	stack_t *new_node, *aux;
	/* Affectation du pointeur vers le sommet de la pile dans la variable aux */
	aux = *head;

	/* Allocation mémoire pour un nouveau nœud */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		/* Affichage d'une erreur si l'allocation a échoué */
		printf("Error\n");
		exit(0);
	}

	/* Si la pile n'est pas vide, met à jour le pointeur du nœud précédent */
	if (aux)
		aux->prev = new_node;

	/* Affectation de la nouvelle valeur au nœud créé */
	new_node->n = n;
	/* Affecte le pointeur vers l'ancien sommet comme suivant du nouveau nœud */
	new_node->next = *head;
	/* Initialisation du pointeur précédent du nouveau nœud à NULL */
	new_node->prev = NULL;

	/* MAJ du ptr vers le sommet de la pile pour pointer vers le nouveau nœud */
	*head = new_node;
}

