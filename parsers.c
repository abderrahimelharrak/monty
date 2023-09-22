#include "monty.h"

/**
 * parse_line - tokenizes a line of text, storing it in line struct
 * @linee: struct containing line contents and line number
 * @buffere: string of text read from script file
 * Return: success
 */
void parse_line(linee_t *linee, char *buffere)
{
	unsigned int x;
	char *tokene = NULL;

	linee->cont = malloc(sizeof(char *) * 3);
	if (!linee->cont)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	tokene = strtok(buffere, " '\n'");
	for (x = 0; tokene && x < 2; x++)
	{
		linee->cont[x] = tokene;
		tokene = strtok(NULL, " \n");
	}

	linee->cont[x] = NULL;
}

/**
 * parse_file - reads and parses file one line at a time
 * @fichier: the script to be read
 * Return: success
 */
void parse_file(FILE *fichier)
{
	size_t sizee = 0;
	metta_t *metta = NULL;
	linee_t linee;

	metta = malloc(sizeof(metta_t));
	if (!metta)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	linee.num = 0;
	linee.cont = NULL;

	metta->fichier = fichier;
	metta->stacke = NULL;
	metta->buff = NULL;

	while (getline(&(metta->buff), &sizee, metta->fichier) != -1)
	{
		linee.num++;
		parse_line(&linee, metta->buff);
		if (linee.cont)
			getopfunc__(linee, metta)(&(metta->stacke), linee.num);
	}

	free(metta->buff);
	free__stack(&(metta->stacke));
	fclose(metta->fichier);
	free(metta);
}
