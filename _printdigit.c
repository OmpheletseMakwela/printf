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
	int n = i, count = 1;
	char c;

	if (i < 0)
	{
		write(1, "-", 1);
		n = i;
		count++;
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
