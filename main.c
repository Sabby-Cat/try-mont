#include "monty.h"
/**
 * main - entry point
 * @argc: nr of arguments
 * @argv: list of arguments
 * Return: 0 or error
 */
int main(int argc, char *argv[])
{
	size_t buff = 1024, count = 0;
	ssize_t line;
	stack_t *head = NULL;
	char  *str = NULL, *ar[2], *tmp;
	void (*operator_function)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		line = getline(&str, &buff, file);
		if (line == -1)
			break;
		count++;
		ar[0] = strtok(str, "\n ");
		if (ar[0] == NULL)
			get_nop(&head, count);
		else if (strcmp("push", ar[0]) == 0)
		{
			tmp = strtok(NULL, "\n ");
			get_push(&head, count, tmp);
		}
		else if (ar[0] != NULL && ar[0][0] != '#')
		{
			operator_function = get_operator(ar[0], count, &head);
			if (operator_function == NULL && count == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					count, ar[0]), exit(EXIT_FAILURE);
			}
		operator_function(&head, count);
		}
	}
	fclose(file), free(str), get_free(head);
	return (0);
}
