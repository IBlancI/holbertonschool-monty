#include "monty.h"

/* Fonction __add: Ajoute les valeurs des deux premiers éléments de la pile */
void __add(stack_t **stack, unsigned int line_number)
{
	/* Vérifie si la pile est trop courte pour l'opération (pour fonction) */
	/* Vérifie si la pile est vide ou s'il y a moins de deux éléments */
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/* Affiche un message d'erreur */
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		/* Indique une erreur */
		error = 1;
		/* Retourne sans effectuer d'opération */
		return;
	}

	/* Ajoute la valeur du premier élément à celle du deuxième */
	(*stack)->next->n += (*stack)->n;
	/* Appelle la fonction __pop pour supprimer le premier élément */
	__pop(stack, line_number);
}

/* Fonction __swap: Echange les deux premiers éléments de la pile */
void __swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	/* Vérifie si la pile est trop courte pour l'opération (for fonction) */
	/* Vérifie si la pile est vide ou s'il y a moins de deux éléments */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		/* Affiche un message d'erreur */
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		/* Indique une erreur */
		error = 1;
		/* Retourne sans effectuer d'opération */
		return;
	}

	/* Stocke la valeur du premier élément dans une variable temporaire */
	tmp = (*stack)->n;
	/* Remplace la valeur du premier élément par celle du deuxième */
	(*stack)->n = (*stack)->next->n;
	/* Remplace la valeur du deuxième élément par la valeur temporaire stockée */
	(*stack)->next->n = tmp;
}
