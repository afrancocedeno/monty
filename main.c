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
	char *buffer = NULL, *function = NULL, *data = NULL;
	size_t 	bytes_qty = 0;
	
	file_pointer = fopen(*(argv + 1), "r");
	getline(&buffer, &bytes_qty, file_pointer);
	printf("printf buffer: %s", buffer);
	function = strtok(buffer, " ");
	printf("monty function: %s\n", function); 
	data = strtok(NULL, "\n");
	printf("monty first data: %s\n", data);
	fclose(file_pointer);
	free(buffer);

	return (0);
}