#include "monty.h"

/**
 * add_op - adds the top two elements together
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void add_op(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (!(*stacke) || !(*stacke)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	(*stacke)->next->n += (*stacke)->n;
	*stacke = (*stacke)->next;
	(*stacke)->prev = NULL;
	free(tmp);
}

/**
 * sub_op - subtracts the top two elements and stores it in second element
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void sub_op(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (!(*stacke) || !(*stacke)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	(*stacke)->next->n -= (*stacke)->n;
	*stacke = (*stacke)->next;
	(*stacke)->prev = NULL;
	free(tmp);
}

/**
 * div_op - divides the top two elements and stores it in second element
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void div_op(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (!(*stacke) || !(*stacke)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	if ((*stacke)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	(*stacke)->next->n /= (*stacke)->n;
	*stacke = (*stacke)->next;
	(*stacke)->prev = NULL;
	free(tmp);
}

/**
 * mul_op - multiplies the top two elements and stores it in second element
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void mul_op(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (!(*stacke) || !(*stacke)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	(*stacke)->next->n *= (*stacke)->n;
	*stacke = (*stacke)->next;
	(*stacke)->prev = NULL;
	free(tmp);
}

/**
 * mod_op - multiplies the top two elements and stores it in second element
 * @stacke: pointer to the head node pointer of stack
 * @n_line: the line number
 * Return: success
 */
void mod_op(stack_t **stacke, unsigned int n_line)
{
	stack_t *tmp;

	if (!(*stacke) || !(*stacke)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	if ((*stacke)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}

	tmp = *stacke;
	(*stacke)->next->n %= (*stacke)->n;
	*stacke = (*stacke)->next;
	(*stacke)->prev = NULL;
	free(tmp);
}
