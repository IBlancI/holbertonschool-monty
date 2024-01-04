#include "monty.h" // Inclusion du fichier d'en-tête monty.h contenant les déclarations et les définitions nécessaires

/**
 * addnode - ajoute un nœud en tête de pile
 * @head: pointeur vers le sommet de la pile
 * @n: nouvelle valeur à ajouter
 * Return: pas de retour
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux; // Déclaration de pointeurs de type stack_t

	aux = *head; // Affectation du pointeur vers le sommet de la pile dans la variable aux

	new_node = malloc(sizeof(stack_t)); // Allocation mémoire pour un nouveau nœud
	if (new_node == NULL)
	{
		printf("Error\n"); // Affichage d'une erreur si l'allocation a échoué
		exit(0); // Sortie du programme
	}

	// Si la pile n'est pas vide, met à jour le pointeur du nœud précédent
	if (aux)
		aux->prev = new_node;

	new_node->n = n; // Affectation de la nouvelle valeur au nœud créé
	new_node->next = *head; // Affectation du pointeur vers l'ancien sommet comme suivant du nouveau nœud
	new_node->prev = NULL; // Initialisation du pointeur précédent du nouveau nœud à NULL

	*head = new_node; // Mise à jour du pointeur vers le sommet de la pile pour pointer vers le nouveau nœud créé
}

