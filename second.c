#include "monty.h"

/**
 * get_pint - prints top element of stack
 * @stack: pointer to head of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * get_pop - pops top element of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: Nothing or exit_failure
 */
void get_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *fir;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	fir = *stack;
	*stack = (*stack)->next;
	if (fir->next)
		fir->next->prev = NULL;
	free(fir);
}

/**
 * get_swap - swaps top two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		fir = *stack;
		sec = fir->next;
		*stack = sec;
		fir->next = sec->next;
		if (sec->next != NULL)
			sec->next->prev = fir;
		sec->prev = NULL;
		sec->next = fir;
		fir->prev = sec;
	}
}
