#include "monty.h"

/**
 * get_push - pushes an element onto top of stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * @tmp: Pointer to instruction
 * Return: nothing or exit_failure
 */
void get_push(stack_t **stack, unsigned int line_number, char *tmp)
{
	stack_t *new;

	(void)line_number;
	if (tmp == NULL || _isdigit(tmp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		get_free(*stack);
		exit(EXIT_FAILURE);
		if (_isdigit(tmp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			get_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(tmp);
	new->next = NULL;
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	*stack = new;
}

/**
 *  _isdigit - checks if char is digit
 *  @str: Char to check
 *  Return: 1 if true else 0
 */

int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}

	return (0);
}
