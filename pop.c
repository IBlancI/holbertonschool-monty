#include "monty.h"

/**
 * f_pop - fonction pour supprimer le sommet de la pile
 * @head: pointeur vers le sommet de la pile
 * @counter: numéro de ligne
 * Return: pas de retour
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h; // Déclare un pointeur temporaire

	if (*head == NULL)
	{
		// Vérifie si la pile est vide, affiche un message d'erreur et quitte le programme
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head; // Stocke l'adresse du sommet de la pile dans h
	*head = h->next; // Met à jour le pointeur de la pile vers le suivant
	free(h); // Libère la mémoire du nœud supprimé (ancien sommet)
}

