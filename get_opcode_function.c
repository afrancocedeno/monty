#include "monty.h"

/**
* get_opcode_function - missi
* @opcode_input: missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void get_opcode_function(char *opcode_input, stack_t **head_list,
	unsigned int line_number)
{
	instruction_t function[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{NULL, NULL}
	};
	int i = 0;
	char *str = NULL;

	while (function[i].opcode != NULL)
	{
		str = function[i].opcode;
		/*if is = 0 the words are identical*/
		if (strcmp(opcode_input, str) == 0)
		{
			function[i].f(head_list, line_number);
			return;
		}
		i++;
	}
	if (function[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_input);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
}

/**
* free_dlistint - function that free double link list
* Return: Nothing
*/

void free_dlistint(void)
{
	stack_t *free_list = var_t.head_list;

	if (free_list == NULL)
		return;

	if (free_list->prev != NULL)
	{
		while (free_list->prev != NULL)
			free_list = free_list->prev;
	}
	else
	{
		while (free_list->next != NULL)
		{
			free_list = free_list->next;
			free(free_list->prev);
		}
	}
	if (var_t.file_pointer)
		fclose(var_t.file_pointer);
	free(free_list);
	free(var_t.buffer);
}
