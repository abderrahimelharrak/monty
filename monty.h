#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct arg_s - doubly linked list representation of a stack (or queue)
 * @argum: points to the previous element of the stack (or queue)
 * @flage: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct arg_s
{
	int argum;
	int flage;
} argum_t;

extern argum_t arg;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line - contents of line and corresponding number
 * @cont: array of tokens read from the line
 * @num: the line number
 * Description: contents of a line and corresponding number
 */
typedef struct line
{
	unsigned int num;
	char **cont;
} linee_t;

/**
 * struct meta_s - doubly linked list representation of a stack (or queue)
 * @buff: char
 * @stacke: stack
 * @fichier: file
 * Description: doubly linked list node
 */
typedef struct meta_s
{
	char *buff;
	stack_t *stacke;
	FILE *fichier;
} metta_t;

void (*getopfunc__(linee_t, metta_t *))(stack_t **, unsigned int);
int is_alpha(int c);

void parse_file(FILE *file);
void parse_line(linee_t *, char *);

bool _commentcheck(linee_t);
void _pushcheck(linee_t, metta_t *, char *);
bool _argumentcheck(char *);

void push_(stack_t **, unsigned int);
void p_all(stack_t **, unsigned int);
void p_int(stack_t **, unsigned int);
void po_p(stack_t **, unsigned int);
void swa_p(stack_t **, unsigned int);
void no_p(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);
void rot_lop(stack_t **, unsigned int);
void rot_rop(stack_t **, unsigned int);
void p_char(stack_t **, unsigned int);
void p_str(stack_t **, unsigned int);
void free__stack(stack_t **);
void q_push(stack_t **, unsigned int);
void add_qu(stack_t **, unsigned int);
void add_st(stack_t **, unsigned int);

void sub_op(stack_t **, unsigned int);
void add_op(stack_t **, unsigned int);
void div_op(stack_t **, unsigned int);
void mul_op(stack_t **, unsigned int);
void mod_op(stack_t **, unsigned int);

#endif /* MONTY_H */
