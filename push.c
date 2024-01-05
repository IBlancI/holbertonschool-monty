#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
        int n, j = 0, flag = 0;

        /* Vérification si bus.arg est défini */
        if (bus.arg)
        {
                /* Vérification du signe "-" pour les entiers négatifs */
                if (bus.arg[0] == '-')
                        j++;

                /* Vérifie chaque caractère pour s'assurer qu'il s'agit d'un chiffre */
                for (; bus.arg[j] != '\0'; j++)
                {
                        if (bus.arg[j] > 57 || bus.arg[j] < 48)
                                /* Élève le drapeau si le caractère n'est pas un chiffre */
                                flag = 1;
                }

                /* Si le drapeau est levé, quitte et affiche un message */
                if (flag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", counter);
                        fclose(bus.file);
                        free(bus.content);
                        free_stack(*head);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                /* Si bus.arg n'est pas défini, quitte et affiche message*/
                fprintf(stderr, "L%d: usage: push integer\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        /* Conversion de bus.arg en entier avec atoi() */
        n = atoi(bus.arg);

        /* Ajout du nœud à la pile ou à la file en fonction de bus.lifi */
        if (bus.lifi == 0)
                addnode(head, n); /* Ajoute un nœud à la pile */
        else
                addqueue(head, n); /* Ajoute un nœud à la f}
