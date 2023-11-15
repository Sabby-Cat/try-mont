#include "main.h"
/**
 * 
 * 
*/
void()
{
    int count;

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
}