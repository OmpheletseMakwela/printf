#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _print_unsigned - prints intergers
 * @i: interger
 * Return: number of characters printed.
 */
int _print_unsigned(unsigned int i)
{
	int count = 1, n = i;
	char c, neg = '-';
	unsigned int x = 0;

	if (i < x)
	{
		write(1, &neg, 1);
		n = i * -1;
	}
	if (n > 9)
	{
		count += _printdigit(n / 10);
		n = n % 10;
	}
	c = n + '0';
	write(1, &c, 1);
	return (count);
}
