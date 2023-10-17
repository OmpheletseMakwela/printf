#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _print_octal - print octal intergers.
 * @i: interger
 * Return: number of characters printed to the stdout.
 */
int _print_octal(int i)
{
	int mod, count = 1;
	char convert;

	if (i == 0)
	{
		return (0);
	}
	else
	{
		count += _print_octal(i / 8);
		mod = i % 8;
		convert = mod + '0';
		write(1, &convert, 1);
	}
	return (count);
}
