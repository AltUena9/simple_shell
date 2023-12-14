#include "shell.h"
/**
 * ch_dir - changes working directory
 * @pth: Curent working directory
 * Return: 0 on success and -1 otherwise
 */

int ch_dir(const char *pth)
{
	char *buff = NULL;
	size_t size = 1024;

	if (pth == NULL)
		pth = getcwd(buff, size);
	if (chdir(pth) == -1)
	{
		perror(pth);
		return (98);
	}
	return (0);
}


/**
 * init_child - Initializes child process
 * @sh: Name of shell
 * @env: Variables in environment
 * @cnd: Poitns to commands that are tokenied
 * @round: No of executed rounds
 * Return: Nothing
 */

void init_child(int round, char **sh, char **env, char **cnd)
{
	pid_t pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();

	if (pid < 0)
	{
		perror("Error: ");
		free_exit(cnd);
	}
	else if (pid == 0)
	{
		execute(cnd, sh, env, round);
		free_dp(cnd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(cnd);
		}
		free_dp(cnd);
	}
}
