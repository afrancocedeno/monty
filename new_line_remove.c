#include "monty.h"

/**
 * new_line_remove - missing description
 * @buffer: missing description
 * Return: Nothing
 */
char *new_line_remove(char *buffer)
{
	int i = 0;

	for (; *(buffer + i) != '\n'; i++)
		;
	*(buffer + i) = '\0';
	return (buffer);
}
