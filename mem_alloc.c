#include "shell.h"
/**
 * free_dp - frees all memory allocated
 * @mem: memory to free
 * Return: Nothing
 */
void free_dp(char **mem)
{
	int i = 0;

	if (mem == NULL)
		return;

	for (i = 0; mem[i] != NULL; i++)
	{
		free(mem[i]);
	}
	free(mem[i]);
	free(mem);
}

/**
 * free_exit - frees memory allocated and exits
 * @mem: memory to free
 * Return: Nothing
 */
void free_exit(char **mem)
{
	free_dp(mem);
	exit(EXIT_FAILURE);
}
