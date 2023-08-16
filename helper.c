#include "shell.h"

/**
 * tokenizer - it tokenizes input and stores it into an array
 *@input_string: the input to be parsed
 *@delim: the delimiter to be used, and needs to be one character string
 *
 *Return: an array of tokens
 */

char **tokenizer(char *input_string, char *delim)
{
	int delim_num = 0;
	char **token_arr = NULL;
	char *token = NULL;
	char *ptr_save = NULL;

	token = _strtok_r(input_string, delim, &ptr_save);

	while (token != NULL)
	{
		token_arr = _realloc(token_arr, sizeof(*token_arr)
		 * delim_num, sizeof(*token_arr) * (delim_num + 1));
		token_arr[delim_num] = token;
		token = _strtok_r(NULL, delim, &ptr_save);
		delim_num++;
	}

	token_arr = _realloc(token_arr, sizeof(*token_arr)
	 * delim_num, sizeof(*token_arr) * (delim_num + 1));
	token_arr[delim_num] = NULL;

	return (token_arr);
}

/**
 *print - prints a string to stdout
 *@string: string to be printed
 *@stream: stream to print out to
 *
 *Return: void, return nothing
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 *remove_newline - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - counts string length
 *@string: string to be counted
 *
 * Return: length of the string
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}
