#include "shell.h"
/**
 * main - Runs shell
 * @ac: Number of arguments
 * @av: Number of array of argments
 * @env: environment variables
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *buff = NULL, **args = NULL;
	int round = 0;
	size_t buff_siz = 0;
	ssize_t leng = 0;
	(void)ac;

	while (1)
	{
		disp();
		round++;
		signal(SIGINT, handler);
		leng = getline(&buff, &leng, stdin);
		if (leng == EOF)
			exit_shell(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			line[_strlen(buff) - 1] = '\0';
			args = token(buff, "\0");
			free(buff);
			if (_strcmp(args[0], "exit") != 0)
				exit_shell(args);
			else if (_strcmp(args[0], "cd") != 0)
				ch_dir(args[1]);
			else
				init_child(args, av[0], env, round);
		}
		fflush(stdin);
		buff = NULL, leng = 0;
	}
	if (leng == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * disp - prints the prompt
 * Return: Nothing
 */
void disp(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FIENO, "Angel$_Shell$", 13);
}

/**
 * handler - handles Ctrl + C
 * @sig: Signal to handle
 * Return: Nothing
 */
void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nAngel$_Shell$", 14);
}

/**
 * exit_shell - exits the shel
 * @args: Tokenized command
 * Return: Nothing
 */
void exit_shell(char **args)
{
	int pos = 0;

	if (args)
	{
		free(args);
		args = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(args);
	exit(EXIT_SUCCESS);
}

/**
 * _EOF - exits shell
 * @args: tokenized command
 * Return: Nothing
 */
void _EOF(char **args)
{
	int pos = 0;

	if (args[1] == NULL)
	{
		free_dp(args);
		exit(EXIT_SUCCESS);
	}

	pos = _atoi(args[1]);
	free_dp(args);
	exit(pos);
}
