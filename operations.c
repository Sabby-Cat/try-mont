#include "monty.h"
/**
 * get_operator - gets the operation
 * @fstr: function string from file
 * @ln: line count
 * @stack: stack
 * Return: nothing or exit_failure
*/
void (*get_operator(char *fstr, unsigned int ln, stack_t **stack))
	(stack_t**, unsigned int)
{
        int i;

	instruction_t operation[] = {
		{"pall", get_pall},
        {"pint", get_pint},
        {"pop", get_pop},
        {"swap", get_swap},
		{"add", get_add},
        {"nop", get_nop},
		{"sub", get_sub},
		{"div", get_div},
		{"mul", get_mul},
		{"mod", get_mod},
        {"pchar", get_pchar},
        {"pstr", get_pstr},
		{"rotl", get_rotl},
		{"rotr", get_rotr},
		{NULL, NULL}
	};
    for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(operation[i].opcode, fstr) == 0)
			return (operation[i].f);
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", ln, fstr);
	fclose(file);
	get_free(*stack);
	exit(EXIT_FAILURE);
}
