#include "monty.h"

/**
 * get_pall - prints all elements of stack
 * @stack: pointer to head of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}

/**
 * get_nop - When no operation present
 * @stack: Header of stack
 * @line_number: line numbers
 * Return: Void
 */
void get_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
