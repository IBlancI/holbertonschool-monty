#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_FAILURE if an error occurs, otherwise EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *line = NULL, *token = NULL;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the file for reading */
	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read and process each line of the file */
	while (getline(&line, &size, file_ptr) != -1 && error != 1)
	{
		line_number++;

		/* Tokenize the line based on whitespace and newline characters */
		token = strtok(line, "\n\t ");
		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue;

		/* Check for the "push" command and handle it accordingly */
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t ");
			__push(token, &stack, line_number);
		}
		else
			get_op_func(token, &stack, line_number);
	}

	/* Clean up and free allocated resources */
	free_all(stack, line, file_ptr);

	/* Exit with EXIT_FAILURE if an error occurred during execution */
	if (error == 1)
		exit(EXIT_FAILURE);

	/* Exit with EXIT_SUCCESS if the program executed successfully */
	return (EXIT_SUCCESS);
}
