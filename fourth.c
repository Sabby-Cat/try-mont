#include "monty.h"
#include <ctype.h>
/**
 * get_pchar - fprints char at top of  stack
 * @stack: pointer to head of the stack
 * @line_number: line number
 * Description: 11. pchar
 * Return: nothing or exit_failure
 */
void get_pchar(stack_t **stack, unsigned int line_number)
{
	if ((stack == NULL) || ((*stack) == NULL))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (!(isascii((*stack)->n)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * get_pstr - prints ascii value of elements
 * @stack: pointer to head of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */

void get_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *fir = *stack;

	(void)line_number;
	if ((stack == NULL) || (*stack == NULL))
		printf("\n");
	else
	{
		while (fir != NULL)
		{
			if ((fir->n > 0) && (isascii(fir->n)))
			{
				printf("%c", fir->n);
				fir = fir->next;
			}
			else
				break;
		}
		printf("\n");
	}
}

/**
 * get_rotl - rotates the tail to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *last;

	(void)line_number;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		fir = last = *stack;
		while (last->next)
			last = last->next;
		*stack = fir->next;
		last->next = fir;
		fir->prev = last;
		fir->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * get_rotr - Rotate the right
 * @stack: Stack
 * @line_number: Line number
 * Return: nothing or exit_failure
 */
void get_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *last;

	(void)line_number;
	if ((*stack == NULL) || ((*stack)->next == NULL))
		;
	else
	{
		fir = last = *stack;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = fir;
		fir->prev = last;
		*stack = last;
	}
}
