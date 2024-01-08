#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	// Définition des opcodes et de leurs fonctions associées
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"queue", f_queue},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	// Séparation du contenu de la ligne en token (opération)
	op = strtok(content, " \n\t");
	// Si la ligne est un commentaire, on la saute
	if (op && op[0] == '#')
		return (0);

	// Récupération de l'argument de l'opération
	bus.arg = strtok(NULL, " \n\t");

	// Parcours de la liste des opcodes pour trouver la correspondance
	while (opst[i].opcode && op)
	{
		// Si l'opcode est trouvé, exécute la fonction associée
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	// Si l'opcode est inconnu, affiche une erreur et arrête le programme
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
