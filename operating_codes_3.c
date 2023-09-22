#include "monty.h"
/**
 * p_int - prints the value at the top of stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void p_int(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (stacke == NULL || *stacke == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}

	printf("%d\n", tmp->n);
}

/**
 * po_p - removes the top element of stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void po_p(stack_t **stacke, unsigned int n_line)
{
	if (stacke == NULL || *stacke == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}
	if ((*stacke)->next != NULL)
	{
		*stacke = (*stacke)->next;
		free((*stacke)->prev);
		(*stacke)->prev = NULL;
	}
	else
	{
		free(*stacke);
		*stacke = NULL;
	}
}

/**
 * swa_p - swaps the top two elements of the stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void swa_p(stack_t **stacke, unsigned int n_line)
{
	int tmp;

	if (stacke == NULL || *stacke == NULL || !((*stacke)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = (*stacke)->n;
	(*stacke)->n = (*stacke)->next->n;
	(*stacke)->next->n = tmp;
}

/**
 * p_char - prints char at top of stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void p_char(stack_t **stacke, unsigned int n_line)
{
	char ctr;
	stack_t *tmp;

	if (stacke == NULL || *stacke == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}

	ctr = tmp->n;
	if (is_alpha(tmp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ctr);
}
/**
 * p_str - prints a str from ascii starting from the top
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: Nothing.
 */
void p_str(stack_t **stacke, unsigned int n_line)
{
	int indx = 0;
	char resp[] = "";
	char ctr;
	stack_t *tmp;

	tmp = *stacke;
	(void)n_line;
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (is_alpha(tmp->n) == 0)
			break;
		ctr = tmp->n;
		printf("%c", ctr);
		resp[indx] += ctr;
		tmp = tmp->next;
		indx++;
	}
	printf("\n");
}
