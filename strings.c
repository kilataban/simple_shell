#include "main.h"

/**
 * _strlen - length of the string
 * @str: the string
 * Return: length
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strdup - duplicate string
 * @dest: the string
 * @src: the source
 * Return: 0
 */

char *_strdup(char *str)
{
	int i;
	char *dest;

	dest = malloc(sizeof(char) * _strlen(str));
	if (!dest)
		return (NULL);
	for (i = 0; str[i]; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copy string
 * @dest: the destination
 * @src: the source
 * Return: 0
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (!src)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concantenate
 * @str: the strings
 * Return: the string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';

	return (dest);
}
