#include "monty.h"

/**
* opcode_push - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_push(stack_t **head_list, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *temp = NULL;
	char *token = NULL;
	int value = 0;
	(void)line_number;

	token = strtok(NULL, " ");
	if (token)
		value = atoi(token);
	else
		value = 0;
	new = (malloc(sizeof(stack_t)));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return;
	}
	new->prev = NULL;
	new->next = *head_list;
	new->n = value;
	if (*head_list == NULL)
		*head_list = new;
	else
	{
		temp = *head_list;
		*head_list = new;
		temp->prev = new;
	}
}

/**
* opcode_pall - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_pall(stack_t **head_list, unsigned int line_number)
{
	stack_t *temp = *head_list;
	(void)line_number;

	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
