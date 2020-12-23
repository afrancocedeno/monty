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

	if (*head_list != NULL || head_list != NULL)
		free(head_list);
	else if (top_element == NULL)
	{
		fprintf(stderr,	"L%d: can't pop an empty stack\n", line_number);
		free(var_t.buffer);
		fclose(var_t.file_pointer);
		exit(EXIT_FAILURE);
	}
	top_element->next->prev = NULL;
	*head_list = (*top_element).next;
	free(top_element);
}
