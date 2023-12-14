#include "shell.h"
/**
 * token - Spliits and creates a full string
 * @ds: delimiter for strtok
 * @buff: Input string
 * Return: Full string command
 */
char **token(char *buff, const char *ds)
{
	char *tok = NULL, **cnd = NULL;
	int i = 0, count = 0;

	if (buff == NULL)
		return (NULL);

	tok = strtok(buff, ds);
	while (tok != NULL)
	{
		count++;
		tok = strtok(NULL, ds);
	}

	cnd = malloc((count + 1) * sizeof(char *));
	if (cnd == NULL)
	{
		perror("Unable to allocate buffer");
		free(buff);
		free_dp(cnd);
		exit(EXIT_FAILURE);
	}

	tok = strtok(buff, ds);
	while (token != NULL)
	{
		cnd[i] = _strdup(tok);
		if (cnd[i] == NULL)
		{
			perror("Unable to allocate buuffer");
			free_d(cnd);
			return (NULL);
		}
		tok = strtok(NULL, ds);
		i++;
	cnd[i] = NULL;
	return (cnd);
}
