#include "monty.h"

/**
 * rot_l - rotates the stack to the top
 * @stacke: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: success
 */
void rot_l(stack_t **stacke, unsigned int nline)
{
	stack_t *tmp;
	int holde_this, holde_this_again;
	(void)nline;

	if (stacke == NULL || *stacke == NULL)
	{
		no_p(stacke, nline);
	}

	holde_this = (*stacke)->n;
	tmp = *stacke;

	while (tmp)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}

	holde_this_again = tmp->n;
	(*stacke)->n = holde_this_again;
	tmp->n = holde_this;
}

/**
 * rot_lop - rotates stack to left
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void rot_lop(stack_t **stacke, unsigned int n_line)
{
	stack_t *laste, *tmpe;

	(void)n_line;
	if (!stacke || !(*stacke) || !((*stacke)->next))
		return;

	tmpe = *stacke;
	laste = tmpe;

	while (laste->next)
	{
		laste = laste->next;
	}

	laste->next = tmpe;
	tmpe->prev = laste;
	tmpe->next->prev = NULL;
	*stacke = tmpe->next;
	tmpe->next = NULL;
}

/**
 * rot_rop - rotates stack to right
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void rot_rop(stack_t **stacke, unsigned int n_line)
{
	stack_t *laste, *tmpe;

	(void)n_line;
	if (!stacke || !(*stacke) || !((*stacke)->next))
		return;

	tmpe = *stacke;
	laste = tmpe;

	while (laste->next)
	{
		laste = laste->next;
	}

	laste->prev->next = NULL;
	laste->prev = NULL;
	tmpe->prev = laste;
	laste->next = tmpe;
	*stacke = laste;
}

/**
 * q_push - pushes for queue instead of stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void q_push(stack_t **stacke, unsigned int n_line)
{
	stack_t *laste, *neww;

	if (stacke == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", n_line);
		exit(EXIT_FAILURE);
	}

	neww = malloc(sizeof(stack_t));
	if (neww == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free__stack(stacke);
		exit(EXIT_FAILURE);
	}

	laste = NULL;
	if (*stacke)
	{
		laste = *stacke;
		while (laste->next)
			laste = laste->next;
		laste->next = neww;
	}
	else
		*stacke = neww;
	neww->prev = laste;
	neww->next = NULL;
	neww->n = arg.argum;
}
