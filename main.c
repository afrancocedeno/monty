#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* free */
#include "monty.h"

/**
* main - missing description
* @argc: missing description
* @argv: missing description
* Return: - missing description
*/
int main(int argc, char **argv)
{
	char *opcode = NULL;

	var_t.line_number = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*open file*/
	var_t.file_pointer = fopen(*(argv + 1), "r");

	if (var_t.file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (; getline(&var_t.buffer, &var_t.bytes_qty, var_t.file_pointer)
		!= EOF; var_t.line_number++)
	{
		/* remove new line */
		if (var_t.buffer == NULL)
			continue;
		var_t.buffer = new_line_remove(var_t.buffer);
		opcode = strtok(var_t.buffer, " ");
		if (opcode != NULL)
			get_opcode_function(opcode, &var_t.head_list, var_t.line_number);
	}
	free_dlistint();
	return (0);
}
