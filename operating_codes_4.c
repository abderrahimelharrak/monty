#include "monty.h"

/**
 * push_ - pushes a node to the top of stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void push_(stack_t **stacke, unsigned int n_line)
{
	stack_t *neww;

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

	neww->next = *stacke;
	neww->prev = NULL;
	neww->n = arg.argum;
	if (*stacke)
		(*stacke)->prev = neww;
	*stacke = neww;
}

/**
 * p_all - prints the data of all nodes in stack
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return:success
 */
void p_all(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;
	(void)n_line;

	tmp = *stacke;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free__stack - frees all nodes in a stack
 * @stacke: pointer to the head node pointer of stack
 * Return: success
 */
void free__stack(stack_t **stacke)
{
	stack_t *tmp = NULL;

	if (stacke == NULL || *stacke == NULL)
		return;

	while (*stacke != NULL)
	{
		tmp = (*stacke)->next;
		free(*stacke);
		*stacke = tmp;
	}
}

/**
 * no_p - does literally nothing
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void no_p(stack_t **stacke, unsigned int n_line)
{
	(void)stacke;
	(void)n_line;
}

/**
 * is_alpha - checks if int is in alphabet
 * @c: int
 * Return: success
 */
int is_alpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}
