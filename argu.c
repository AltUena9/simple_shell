#include <stdio.h>

/**
 * main -  prints all arguments without ac
 * @av: NULL terminated array of strings
 * @ac: number of items in av
 * Return: Nothing
 */

int main(int ac, char **av)
{
	char *arg;

	while ((arg = *av++) != NULL)
	{
		printf("%s\n", arg);
	}

	return (0);
}
