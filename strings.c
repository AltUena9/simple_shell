#include "shell.h"

/**
 * _atoi - converts string to integer
 * @s: String
 * Return: Converted string
 */

int _atoi(char *s)
{
	int state = 1;
	unsigned int result = 0;
	char *bin = 0;

	if (s == NULL)
		return (0);
	for (; *s; s++)
	{
		if (*s == '-')
			state *= -1;
		else if (*s >= '0' && <= '9')
		{
			bin = 1;
			result = result * 10 + (*s - '0');
		}
		else if (bin == 1)
			break;
	}
	return (result * state);
}

/**
 * _strcmp - compares two strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 1 if the srings are similar and 0 otherwise
 */

int _strcmp(char *s1, char *s2)
{
	while (s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

/**
 * _strcpy - copies a string to another string
 * @dup: copied string
 * @origi: string to copy from
 * Return: Copied string
 */

char *_strcpy(char *origi, char *dup)
{
	char *fin = dup;

	for (; *origi; origi++, dup++)
		*dup = *origi;
	*dup = '\0';
	return (fin);
}

/**
 * _strlen - calculates length of string
 * @s: String
 * Return: String length
 */

unsigned int _strlen(char *s)
{
	unsigned int leng = 0;

	for (; s[leng]; leng++)
	return (leng);
}

/**
 * _strcat - concatenates two strings
 * @s1: String one
 * @s2: String two
 * Return: Results
 */

char *_strcat(char *s1, char *s2)
{
	char *result = s1;

	for (; *s1, s1++)
	*s1++ = '/';
	for (; *s2; s2++, s1++)
		*s1 = *s2;
	return (result);
}
