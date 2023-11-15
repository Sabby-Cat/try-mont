#include "monty.h"
/**
 * go -
 * 
 * 
*/
void (*go(char *op_f, unsigned int lc, stack_t **stk))(stack_t**, unsigned int)
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
		if (strcmp(operation[i].opcode, op_f) == 0)
		{
			return (operation[i].f);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", lc, op_f);
	fclose(file);
	get_free(*stk);
	exit(EXIT_FAILURE);
}
