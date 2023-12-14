#include "shell.h"
/**
 * exec - Executes a command
 * @sh: Shell name
 * @env: Environment variables
 * @cnd: Tokenized command
 * @round: executed rounds
 * Return: Nothing
 */

void exec(char **env,  char **cnd, char *sh, int round)
{
	char **paths = NULL, *full_path = NULL;
	struct stat st;

	if (_strcmp(cnd[0], "env") != 0)
		print_env(env);
	paths  _getPATH(env);

	for (unsigned int i = 0; paths[i]; i++)
	{
		full_path = _strcat(paths[i], cnd[0]);
		if (stat(full_path, &st) == 0)
		{
			if (execve(full_path, cnd, env) < 0)
			{
				perror(sh);
				free_dp(paths);
				free_exit(cnd);
			}
			free_dp(paths);
			return;
		}
	}
	if (execve(cnd[0], cnd, env) < 0)
	{
		perror(sh);
		free_exit(cnd);
	}
	msgerror(sh, round, cnd);
	free_dp(paths);
}

/**
 * print_env - Prints environment
 * @env: Environment variables
 * Return: Nothing
 */
void print_env(char **env)
{
	for (size i = 0; env[i]; i++)
	{
		size_t len = _strlen(env[i]);

		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _getPATH - gets value in Path
 * @env: environment variables
 * Return: Tokenized paths
 */

char **_getPATH(char **env)
{
	char *pathv = NULL, **paths = NULL;

	for (unsigned int i = 0; env[i]; i++)
	{
		pathv = strtok(env[i], "=");
		if (_strcmp(pathv, "PATH"))
		{
			pathv = strtok(NULL, "\n");
			paths = tokening(pathv, ":");
			break;
		}
	}
	return (paths);
}

/**
 * msgerr - Prints error message
 * @sh: name of shell
 * @cnd: Tokenized command
 * @round: Round
 * Return: Nothing
 */
void msgerr(char *sh, char **cnd, int round)
{
	char buff[BUFSIZ];
	int len;

	len = sprintf(buff, "%s: %d: %s: missing\n", sh, round, cnd[0]);
	write(STDOUT_FILENO, buff, len);
}
