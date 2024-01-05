#include "monty.h"

 bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - interprèteur de code Monty
 * @argc: nombre d'arguments passés au programme
 * @argv: tableau d'arguments passés au programme
 * Return: 0 en cas de succès
 */
int main(int argc, char *argv[])
{
	/* Pointeur vers le contenu de chaque ligne lue */
	char *content;
	/* Pointeur vers le fichier Monty */
	FILE *file;
	/* Taille initiale allouée pour lire chaque ligne */
	size_t size = 0;
	/* Variable pour stocker le résultat de la lecture de chaque ligne */
	ssize_t read_line = 1;
	/* Initialisation de la pile à NULL (aucun élément) */
	stack_t *stack = NULL;

	/* Initialisation du compteur de lignes à 0 */
	unsigned int counter = 0;

	/* Vérifie s'il y a exactement 2 arguments passés au programme */
	if (argc != 2)
	{
		/* Affichage d'un message d'erreur sur la sortie d'erreur standard */
		fprintf(stderr, "USAGE: monty file\n");
		/* Sortie du programme avec un code d'erreur */
		exit(EXIT_FAILURE);
	}

	/* Ouverture du fichier Monty en lecture */
	file = fopen(argv[1], "r");
	/* Stockage du pointeur vers le fichier dans la structure bus */
	bus.file = file;

	/* Vérification si le fichier s'est bien ouvert */
	if (!file)
	{
		/* Affichage d'un message d'erreur si l'ouverture a échoué */
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		/* Sortie du programme avec un code d'erreur */
		exit(EXIT_FAILURE);
	}

	/* Boucle pour lire chaque ligne du fichier Monty */
	while (read_line > 0)
	{
		/* Initialisation du pointeur de contenu à NULL */
		content = NULL;
		/* Lecture d'une ligne du fichier dans la variable content */
		read_line = getline(&content, &size, file);
		/* Stockage du contenu de la ligne lue dans la structure bus */
		bus.content = content;
		/* Incrémentation du compteur de lignes */
		counter++;

		/* Vérification si une ligne a été lue avec succès */
		if (read_line > 0)
		{
			/* Exécution de la commande Monty pour la ligne lue */
			execute(content, &stack, counter, file);
		}
		/* Libération de la mémoire allouée pour stocker le contenu de la ligne */
		free(content);
	}
	/* Libération de la mémoire utilisée par la pile */
	free_stack(stack);
	/* fermeture du fichier Monty */
	fclose(file);

	return (0);
}
