#include "monty.h"

/**
 * get_add - adds top two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_add(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fir = *stack;
		sec = fir->next;
		sec->n += fir->n;
		*stack = sec;
		(*stack)->prev = NULL;
		free(fir);
	}
}

/**
 * get_sub - subtracts top two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fir = *stack;
		sec = fir->next;
		sec->n -= fir->n;
		*stack = sec;
		(*stack)->prev = NULL;
		free(fir);
	}
}

/**
 * get_div - dividestop two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_div(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(file);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fir = *stack;
		sec = fir->next;
		sec->n /= fir->n;
		*stack = sec;
		(*stack)->prev = NULL;
		free(fir);
	}
}

/**
 * get_mul - multiples top two elements of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: nothing or exit_failure
 */
void get_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	else
	{
		fir = *stack;
		sec = fir->next;
		sec->n *= fir->n;
		*stack = sec;
		(*stack)->prev = NULL;
		free(fir);
	}
}

/**
 * get_mod - finds modulus of top two elements
 * @stack: pointer to the top of the stack
 * @line_number: line number 
 * Return: nothing or exit_failure
 */
void get_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *fir, *sec;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fir = *stack;
		sec = fir->next;
		sec->n %= fir->n;
		*stack = sec;
		(*stack)->prev = NULL;
		free(fir);
	}
}