#include "monty.h"

/* Fonction __push : Ajoute un nouvel élément à la pile */
void __push(char *token, stack_t **stack, unsigned int line_number)
{
	/* Vérification si le token est NULL */
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error = 1;
		return;
	}

	int i = 0;
	/* Vérification de chaque caractère dans le token pour s'assurer qu'il s'agit d'un entier */
	while (token[i] != '\0')
	{
		if (token[i] == '-')
			i++;
		if (!isdigit(token[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			error = 1;
			return;
		}
		i++;
	}

	/* Allocation d'un nouvel élément de la pile */
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}

	/* Assignation de la valeur de l'entier converti à newNode */
	newNode->n = atoi(token);
	newNode->next = *stack;
	newNode->prev = NULL;

	/* Vérification si la pile n'est pas vide, et ajustement des liens */
	if (*stack)
		(*stack)->prev = newNode;

	/* Mise à jour du pointeur de la pile vers le nouvel élément */
	*stack = newNode;
}

/* Fonction __pall : Affiche tous les éléments de la pile */
void __pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Ignorer l'argument line_number */
	stack_t *h = *stack;

	/* Parcours de la pile et affichage de chaque élément */
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/* Fonction __nop : Fonction vide (aucune opération) */
void __nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Ignorer l'argument stack */
	(void)line_number; /* Ignorer l'argument line_number */
}

/* Fonction __pint : Affiche la valeur du premier élément de la pile */
void __pint(stack_t **stack, unsigned int line_number)
{
	/* Vérification si la pile est vide */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	/* Affichage de la valeur du premier élément */
	printf("%d\n", (*stack)->n);
}

/* Fonction __pop : Supprime le premier élément de la pile */
void __pop(stack_t **stack, unsigned int line_number)
{
	/* Vérification si la pile est vide */
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}

	/* Stockage de l'adresse de l'élément à supprimer */
	stack_t *tmp = *stack;
	/* Mise à jour du pointeur de la pile vers le deuxième élément */
	*stack = (*stack)->next;

	/* Si la pile n'est pas vide, ajustement des liens */
	if (*stack)
		(*stack)->prev = NULL;

	/* Libération de la mémoire de l'élément supprimé */
	free(tmp);
}
