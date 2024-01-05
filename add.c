#include "monty.h"

/**
 * f_add - fonction pour additionner les deux premiers éléments de la pile
 * @head: pointeur vers le sommet de la pile
 * @counter: numéro de ligne
 * Return: pas de retour
 */
void f_add(stack_t **head, unsigned int counter)
{
	/* Déclaration d'un pointeur temporaire */
	stack_t *h;
	/* Initialisation des variables */
	int len = 0, aux;

	/* Initialise h avec l'adresse du sommet de la pile */
	h = *head;

	/* Calcule la taille de la pile en parcourant tous les éléments */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Vérifie si la pile contient au moins deux éléments */
	if (len < 2)
	{
		/* quitte et affiche un message quand la pile est trop courte */
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Réinitialise h avec l'adresse du sommet de la pile */
	h = *head;
	/* Additionne les valeurs des deux premiers éléments */
	aux = h->n + h->next->n;
	/* Stocke le résultat dans le deuxième élément de la pile */
	h->next->n = aux;
	/* Met à jour le pointeur de la pile vers le deuxième élément */
	*head = h->next;
	/* Libère la mémoire du premier élément supprimé */
	free(h);
}
