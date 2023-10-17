#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _putchar - prints out character.
 * @c: character
 * Return: o (success).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _print_hex_string - prints out string and unprintable characters.
 * @s: string
 * Return: number of character printed.
 */
int _print_hex_string(char *s)
{
	int convert, len = _strlen(s), count = 0, x;

	for (x = 0; x < len; x++)
	{
		convert = s[x];
		if (convert < 32 || convert >= 127)
		{
			_putchar('\\');
			count++;
			_putchar('x');
			count++;
			_putchar('0');
			count++;
			count += hexadecimal(convert);
		}
		else
		{
			write(1, &s[x], 1);
			count++;
		}
	}
	return (count);
}
