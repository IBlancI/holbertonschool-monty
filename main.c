#include "monty.h" // Inclusion du fichier d'en-tête monty.h contenant les déclarations et les définitions nécessaires

bus_t bus = {NULL, NULL, NULL, 0}; // Initialisation de la structure bus_t à NULL et 0

/**
 * main - interprèteur de code Monty
 * @argc: nombre d'arguments passés au programme
 * @argv: tableau d'arguments passés au programme (contient le chemin du fichier Monty)
 * Return: 0 en cas de succès
 */
int main(int argc, char *argv[])
{
	char *content; // Pointeur vers le contenu de chaque ligne lue
	FILE *file; // Pointeur vers le fichier Monty
	size_t size = 0; // Taille initiale allouée pour lire chaque ligne
	ssize_t read_line = 1; // Variable pour stocker le résultat de la lecture de chaque ligne
	stack_t *stack = NULL; // Initialisation de la pile à NULL (aucun élément)

	unsigned int counter = 0; // Initialisation du compteur de lignes à 0

	// Vérifie s'il y a exactement 2 arguments passés au programme (nom du programme inclus)
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"); // Affichage d'un message d'erreur sur la sortie d'erreur standard
		exit(EXIT_FAILURE); // Sortie du programme avec un code d'erreur
	}

	// Ouverture du fichier Monty en lecture
	file = fopen(argv[1], "r");
	bus.file = file; // Stockage du pointeur vers le fichier dans la structure bus

	// Vérification si le fichier s'est bien ouvert
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]); // Affichage d'un message d'erreur si l'ouverture a échoué
		exit(EXIT_FAILURE); // Sortie du programme avec un code d'erreur
	}

	// Boucle pour lire chaque ligne du fichier Monty
	while (read_line > 0)
	{
		content = NULL; // Initialisation du pointeur de contenu à NULL
		read_line = getline(&content, &size, file); // Lecture d'une ligne du fichier dans la variable content
		bus.content = content; // Stockage du contenu de la ligne lue dans la structure bus
		counter++; // Incrémentation du compteur de lignes

		// Vérification si une ligne a été lue avec succès
		if (read_line > 0)
		{
			execute(content, &stack, counter, file); // Exécution de la commande Monty pour la ligne lue
		}

		free(content); // Libération de la mémoire allouée pour stocker le contenu de la ligne
	}

	free_stack(stack); // Libération de la mémoire utilisée par la pile
	fclose(file); // Fermeture du fichier Monty

	return (0); // Retourne 0 pour indiquer une exécution réussie du programme
}

