#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _print_binary - Prints a binary value
 * @i: integer
 * Return: 0 always a success
 */
int _print_binary(int i)
{
	int mod;
	int count = 1;
	char convert;

	if (i == 0)
	{
		return (0);
	}
	else
	{
		count += _print_binary(i / 2);
		mod = i % 2;
		convert = mod + '0';
		write(1, &convert, 1);
	}
	return (count);
}
