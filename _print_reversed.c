#include "main.h"
/**
 *_print_reverse - prints reversed string.
 *@s: string
 *Return: number of characters printed.
 */
int _print_reverse (char *s)
{
	int max = _strlen(s) - 1, i, count = 0;
	for (i = 0; i <= max; max--)
	{
		_putchar(s[max]);
		count++;
	}
	return (count);
}
