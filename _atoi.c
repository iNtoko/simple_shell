#include "shell.h"

/**
 * interactive - returns true when shell is in interactive mode
 * @info: struct addresses
 *
 * Return: 1 when is in interactive mode, 0 if its not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks characters if they are delimiters
 * @c: the characters to check
 * @delim: the delimiter strings
 * Return: 1 if yes, 0 if no
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks alphabetic characters
 * @c: Character to input
 * Return: 1 if c is alphabetic, 0 if its not alphabetic
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts strings to integers
 * @s: Strings to convert
 * Return: 0 if theres no numbers in the string, converts numbers if otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

