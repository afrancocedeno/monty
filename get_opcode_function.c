#include "monty.h"

void opcode_push(stack_t **head_list, unsigned int line_number);
void opcode_pall(stack_t **head_list, unsigned int line_number);
/**
 * get_opcode_funciton -
 * @head_list:
 * @opcode_input:
 * @line_number:
 */
void get_opcode_function(char *opcode_input, stack_t **head_list, unsigned int line_number)
{
	instruction_t function[] = {
	    {"push", opcode_push},
	    {"pall", opcode_pall},
	    {NULL, NULL}};
	int i = 0;

	/* find the input function in our opcode function */
	for (; function[i].opcode != NULL && *(function[i].opcode) != opcode_input; i++)
		;
	function[i].f(head_list, line_number);
}
