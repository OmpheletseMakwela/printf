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
/**
 * _strlen - A function that returns the length of a string
 * @c: the function argument
 * Return: the length
 */
int _strlen(char *c)
{
	int length = 0;

	for (; *c != '\0'; c++)
	{
		length++;
	}
	return (length);
}

/**
 * _string - String func
 * @str: A pointer to a character
 * Return: The string length
 */
int _string(char *str)
{
	int length = _strlen(str);

	write(1, str, length);
	return (length);
}

/**
 * _printf - A function that prints a formatted string
 * @format: the fisrt argument of a function
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i, count = 0;
	char c, *str;

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(arg, char *);
				count += (_string(str) - 1);
			}
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				_printdigit(va_arg(arg, int));
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
