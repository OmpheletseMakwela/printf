#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
/**
 * _printdigit - prints out a interger.
 * @i: interger
 * Return: 0 (success)
 */
int _printdigit(int i)
{
	int n = i;
	char c, neg = '-';

	if (i < 0)
	{
		write(1, &neg, 1);
		n = i * -1;
	}
	if (n > 9)
	{
		_printdigit(n / 10);
		n = n % 10;
	}
	c = n + '0';
	write(1, &c, 1);
	return (0);
}
