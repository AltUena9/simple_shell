#include <stdio.h>

int main(int ac, char **av)
{
	char *arg;

	while ((arg = *av++) != NULL)
	{
		printf("%s\n", arg);
	}

	return 0;
}
