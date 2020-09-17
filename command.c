#include "monty.h"
/**
 * command - functions that tokenize getline buffer
 * @buffer: getline's buffer with the commands and args
 * @stack: pointer to stack
 * @line: line number
 * Return: void
 */
int command(char *buffer, stack_t **stack, unsigned int line)
{
	/*Tokenize the content od the file*/
	char *token, *token_array[100], *del = " \n\t";
	int i = 0;
	stack_t *aux;
	(void)aux;

	token = strtok(buffer, del);
	if (token == NULL)
		return (EXIT_SUCCESS);
	while (i < 2)
	{
		token_array[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	token_array[i] = NULL;
	if (strcmp(token_array[0], "push") == 0)
		aux = op_push(stack, token_array[1], line);
	else if (strcmp(token_array[0], "#") == 0)
		op_nop(stack, line);
	else
		get_op(token_array[0], stack, line);
	return (EXIT_SUCCESS);
}
