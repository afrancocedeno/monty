#include "monty.h"

/**
* get_opcode_function - missing description
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
	free(free_list);
}
