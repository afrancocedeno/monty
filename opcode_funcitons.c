#include "monty.h"

/**
* opcode_push - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_push(stack_t **head_list, unsigned int line_number)
{
	stack_t *new = NULL, *temp = NULL;
	char *date = NULL;
	int value = 0, i = 0;

	date = strtok(NULL, " ");
	if (date == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(), exit(EXIT_FAILURE);
	}
	while (date[i] != '\0')
	{
		/*Return 1 when numeric character is passed*/
		if (isdigit(date[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_dlistint();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	value = atoi(date);
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

/**
* opcode_pint - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_pint(stack_t **head_list, unsigned int line_number)
{
	stack_t *top_element = *head_list;
	(void)line_number;

	printf("%d\n", (*top_element).n);
}
/**
* opcode_pop - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_pop(stack_t **head_list, unsigned int line_number)
{
	stack_t *top_element = *head_list;
	(void)line_number;

	if (top_element->next != NULL)
	{
		top_element->next->prev = NULL;
		*head_list = (*top_element).next;
		free(top_element);
	}
	else if (head_list == NULL || *head_list == NULL)
		free_dlistint();
}

/**
* opcode_swap - missing description
* @head_list: missing description
* @line_number: missing description
* Return: Nothing
*/
void opcode_swap(stack_t **head_list, unsigned int line_number)
{
	int aux_n;
	stack_t *ptr_tmp = *head_list;

	if (ptr_tmp == NULL)
		return;

	if (ptr_tmp->next->next == NULL || ptr_tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	aux_n = ptr_tmp->next->n;
	ptr_tmp->next->n = ptr_tmp->n;
	ptr_tmp->n = aux_n;
}
