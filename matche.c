#include "monty.h"

/**
 * getopfunc__ - function searches for a match between opcode and text returns the corresponding function
 * @linee: struct containing line contents and line number
 * @metta: struct containing all allocated memory
 * Return: success
 */
void (*getopfunc__(linee_t linee, metta_t *metta))(stack_t **, unsigned int)
{
	unsigned int x = 0;
	instruction_t op_s[] = {
		{"push", push_},
		{"pall", p_all},
		{"pint", p_int},
		{"pop", po_p},
		{"swap", swa_p},
		{"add", add_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"nop", no_p},
		{"pchar", p_char},
		{"pstr", p_str},
		{"rotl", rot_lop},
		{"rotr", rot_rop},
		{"stack", add_st},
		{"queue", add_qu},
		{NULL, NULL}
	};

	if (_commentcheck(linee))
		return (no_p);

	while (op_s[x].opcode)
	{
		if (strcmp(op_s[x].opcode, linee.cont[0]) == 0)
		{
			_pushcheck(linee, metta, op_s[x].opcode);
			if (arg.flage == 1 &&
			strcmp(op_s[x].opcode, "push") == 0)
			{
				if (linee.cont)
					free(linee.cont);
				return (q_push);
			}
			free(linee.cont);
			return (op_s[x].f);
		}

		x++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", linee.num,
	linee.cont[0]);
	free(linee.cont);
	free(metta->buff);
	free__stack(&(metta->stacke));
	fclose(metta->fichier);
	free(metta);
	exit(EXIT_FAILURE);
}
