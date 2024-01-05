#include "monty.h"

/**
 * f_pop - fonction pour supprimer le sommet de la pile
 * @head: pointeur vers le sommet de la pile
 * @counter: numéro de ligne
 * Return: pas de retour
 */
void f_pop(stack_t **head, unsigned int counter)
{
	 /* Déclare un pointeur temporaire */
	stack_t *h;

	if (*head == NULL)
	{
		/* quitte et affiche un message d'erreur quand la pile est vide */
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Stocke l'adresse du sommet de la pile dans h */
	h = *head;
	/* Met à jour le pointeur de la pile vers le suivant */
	*head = h->next;
	/* Libère la mémoire du nœud supprimé (ancien sommet) */
	free(h);
}

