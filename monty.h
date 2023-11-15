#ifndef _MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern FILE *file;

/****operation****/
void (*operator_function)(stack_t **, unsigned int);
void (*go(char *op_f, unsigned int l, stack_t **s))(stack_t**, unsigned int);

/****first****/
void get_nop(stack_t **stack, unsigned int line_number);
void get_pall(stack_t **stack, unsigned int line_number);

/****second****/
void get_pint(stack_t **stack, unsigned int line_number);
void get_pop(stack_t **stack, unsigned int line_number);
void get_swap(stack_t **stack, unsigned int line_number);

/****third****/
void get_add(stack_t **stack, unsigned int line_number);
void get_sub(stack_t **stack, unsigned int line_number);
void get_div(stack_t **stack, unsigned int line_number);
void get_mul(stack_t **stack, unsigned int line_number);
void get_mod(stack_t **stack, unsigned int line_number);

/****fourth****/
void get_pchar(stack_t **stack, unsigned int line_number);
void get_rotl(stack_t **stack, unsigned int line_number);
void get_rotr(stack_t **stack, unsigned int line_number);
void get_pstr(stack_t **stack, unsigned int line_number);

void get_free(stack_t *stack);
void get_push(stack_t **stack, unsigned int line_number, char *tmp);
int _isdigit(char *str);


#endif
