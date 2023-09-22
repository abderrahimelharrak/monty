#include "monty.h"

/**
 * main - opens a monty script file for parsing
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fichier;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fichier = fopen(argv[1], "r");
	if (!fichier)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_file(fichier);
	return (EXIT_SUCCESS);
}
