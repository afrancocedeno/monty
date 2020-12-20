#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* free */
#include "monty.h"

/**
 * 
 *
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	FILE *file_pointer = NULL;
	char *buffer = NULL, *function = NULL, *data = NULL;
	size_t bytes_qty = 0;

	file_pointer = fopen(*(argv + 1), "r");
	while (getline(&buffer, &bytes_qty, file_pointer) != EOF)
	{
		/* remove new line */
		buffer = new_line_remove(buffer);
		/* interprete monty opcode */
		function = strtok(buffer, " ");
		printf("%s\n", function);
		data = strtok(NULL, " , \n");
		printf("%s\n", data);
	}
	fclose(file_pointer);
	free(buffer);
	return (0);
	/* edge cases, no number argument */
	/* edge case, more or less than two argvs */
}
