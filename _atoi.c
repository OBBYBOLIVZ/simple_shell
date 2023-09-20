#include "shell.h"

/**
 * interactive - Check if the shell is in interactive mode.
 *
 * @info: Pointer to the information structure.
 *
 * Return: Return 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if a character is a delimiter.
 *
 * @c: The character to check.
 * @delim: Delimiter string.
 *
 * Return: Return 1 if 'c' is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Check if a character is alphabetic.
 *
 * @c: The character to check.
 *
 * Return: Return 1 if 'c' is alphabetic, otherwise return 0.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Convert a string to an integer.
 *
 * @s: The string to be converted.
 *
 * Return: Return 0 if there are no numbers in the string,
 * otherwise the converted number.
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
