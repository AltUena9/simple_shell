#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * STRING.C
 */

char *_strcat(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *origi, char *dup);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);

/**
 * SHELL.C
 */

int main(int ac, char **av, char **env);
void disp(void);
void handler(int sig);
void exit_shell(char **args);
void _EOF(char **args);

/**
 * EXEC.C
 */

void msgerr(char *sh, char **cnd, int round);
char **_getPATH(char **env);
void print_env(char **env);
void exec(char **env,  char **cnd, char *sh, int round);

/**
 * MEM_ALLOC.C
 */

void free_dp(char **mem);
void free_exit(char **mem);

/**
 * CHILD_P.C
 */

int ch_dir(const char *pth);
void init_child(int round, char **sh, char **env, char **cnd);

/**
 * TOKENIZER.C
 */

char **token(char *buff, const char *ds);

#endif
