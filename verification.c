#include "monty.h"

argum_t argum = {0, 0};

/**
 * _commentcheck - checks if line is a comment
 * @linee: struct containing line contents and line number
 * Return: success
 */
bool _commentcheck(linee_t linee)
{
	if (!linee.cont[0])
	{
		free(linee.cont);
		return (true);
	}

	if (linee.cont[0][0] == '#')
	{
		free(linee.cont);
		return (true);
	}

	return (false);
}

/**
 * _argumentcheck - verifies argument is valid
 * @tokenu: the argument to be checked
 * Return: success
 */
bool _argumentcheck(char *tokenn)
{
	unsigned int x;

	if (!tokenn)
		return (false);

	for (x = 0; tokenn[x]; x++)
	{
		if (tokenn[0] == '-')
			continue;
		if (tokenn[x] < '0' || tokenn[x] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * _pushcheck - check if push opcode is being used and sets global arguments
 * @linee: struct containing line contents and line number
 * @op_code: the opcode to compare
 * @metta: struct containing all allocated memory
 * Return: success
 */
void _pushcheck(linee_t linee, metta_t *metta, char *op_code)
{
	if ((strcmp(op_code, "push") == 0) && !_argumentcheck(linee.cont[1]))
	{
		free(linee.cont);
		fprintf(stderr, "L%d: usage: push integer\n", linee.num);
		free(metta->buff);
		free__stack(&(metta->stacke));
		fclose(metta->fichier);
		free(metta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(op_code, "push") == 0)
		argum.argum = atoi(linee.cont[1]);
}
