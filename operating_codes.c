#include "monty.h"

/**
 * add_st - changes mode of push to stack
 * @stacke: pointer to stack
 * @nlinee: line number
 * Return: success
 */
void add_st(stack_t **stacke, unsigned int nlinee)
{
	(void)nlinee;
	(void)stacke;

	arg.flage = 0;
}

/**
 * add_qu - changes mode of push to queue
 * @stacke: pointer to stack
 * @n_line: line number
 * Return: success
 */
void add_qu(stack_t **stacke, unsigned int n_line)
{
	(void)n_line;
	(void)stacke;

	arg.flage = 1;
}
