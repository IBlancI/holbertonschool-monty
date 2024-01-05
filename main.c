#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
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
