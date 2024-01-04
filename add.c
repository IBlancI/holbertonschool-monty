#include "monty.h"

/**
 * f_add - fonction pour additionner les deux premiers éléments de la pile
 * @head: pointeur vers le sommet de la pile
 * @counter: numéro de ligne
 * Return: pas de retour
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h; // Déclaration d'un pointeur temporaire
	int len = 0, aux; // Initialisation des variables

	h = *head; // Initialise h avec l'adresse du sommet de la pile

	// Calcule la taille de la pile en parcourant tous les éléments
	while (h)
	{
		h = h->next;
		len++;
	}

	// Vérifie si la pile contient au moins deux éléments
	if (len < 2)
	{
		// Si la pile est trop courte, affiche un message d'erreur et quitte le programme
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head; // Réinitialise h avec l'adresse du sommet de la pile
	aux = h->n + h->next->n; // Additionne les valeurs des deux premiers éléments
	h->next->n = aux; // Stocke le résultat dans le deuxième élément de la pile
	*head = h->next; // Met à jour le pointeur de la pile vers le deuxième élément
	free(h); // Libère la mémoire du premier élément supprimé
}

