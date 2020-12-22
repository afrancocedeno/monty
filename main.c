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
	char *opcode = NULL, *token_1 = NULL;
	(void)token_1;

	if (argc > 2 || argc == 0)
	{
		printf("USAGE: monty file");
		return (EXIT_FAILURE);
	}
	if (argv[0] == NULL)
	{
		printf("Error: Can't open file <file>\n");
		return (EXIT_FAILURE);
	}

	/*open file*/
	var_t.file_pointer = fopen(*(argv + 1), "r");
	for (; getline(&var_t.buffer, &var_t.bytes_qty, var_t.file_pointer)
		!= EOF; var_t.line_number++)
	{
		/* remove new line */
		var_t.buffer = new_line_remove(var_t.buffer);
		opcode = strtok(var_t.buffer, " ");
		get_opcode_function(opcode, &var_t.head_list, var_t.line_number);
	}

	fclose(var_t.file_pointer);
	free_dlistint();
	free(var_t.buffer);
	return (0);
}
