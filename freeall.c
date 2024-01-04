#include "monty.h"

/**
 * free_all - function that frees all and closes the file
 * @stack: the list to free
 * @line: the line of getline to free
 * @ptr: the file to close
 */
void free_all(stack_t *stack, char *line, FILE *ptr)
{
	/* Déclare un pointeur temporaire pour stocker la valeur actuelle de stack */
	stack_t *temp = stack;

	/* Boucle while pour libérer tous les éléments de la liste liée (stack) */
	while (stack != NULL)
	{
		/* Stocke l'élément actuel de stack dans temp */
		temp = stack;
		/* Avance stack au prochain élément de la liste */
		stack = stack->next;
		/* Libère la mémoire de l'élément actuel (temp) */
		free(temp);
	}

	/* Libère la mémoire allouée pour la ligne getline */
	free(line);
	/* Ferme le fichier pointé par ptr */
	fclose(ptr);
}
