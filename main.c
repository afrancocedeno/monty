#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* free */
#include "monty.h"

/**
 * 
 *
 */
int main(__attribute__((unused))int argc, char **argv)
{
	FILE *file_pointer = NULL;
	char *buffer = NULL, *opcode = NULL;
	size_t bytes_qty = 0;
	stack_t *head_list = NULL;
	int line_number = 1;

	file_pointer = fopen(*(argv + 1), "r");
	for (; getline(&buffer, &bytes_qty, file_pointer) != EOF; line_number++)
	{
		/* remove new line */
		buffer = new_line_remove(buffer);
		/* get opcode = pall or push */
		opcode = strtok(buffer, " ");
		/* get the opcode, no need to return */
		get_opcode_function(opcode)(&head_list, line_number);
		/* *data = NULL ??????????? data = strtok(NULL, " , \n");
		printf("%s\n", data); */
	}
	fclose(file_pointer);
	free(buffer);
	return (0);
}
