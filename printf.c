#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
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
	char c, *str, b2;
	unsigned int b;
	short int h;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
				i++;
				count++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(arg, char *);
				i++;
				count += _string(str);
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i], 1);
				i++;
				count++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				count += _printdigit(va_arg(arg, int));
				i++;
			}
			else if (format[i + 1] == 'b')
			{
				b = va_arg(arg, unsigned int);
				if (b != 0)
				{
					count += _print_binary(b);
				}
				else
				{
					b2 = '0';
					write(1, &b2, 1);
					count++;
				}
				i++;
			}
			else if (format[i + 1] == 'x')
			{
				count += hex(va_arg(arg, int));
				i++;
			}
			else if (format[i + 1] == 'R')
			{
				count += _print_rot23(va_arg(arg, char *));
				i++;
			}
			else if (format[i + 1] == 'X')
			{
				count += hexadecimal(va_arg(arg, int));
				i++;
			}
			else if (format[i + 1] == 'o')
			{
				count += _print_octal(va_arg(arg, int));
				i++;
			}
			else if (format[i + 1] == 'u')
			{
				count += _print_unsigned(va_arg(arg, unsigned int));
				i++;
			}
			else if (format[i + 1] == 'S')
			{
				count += _print_hex_string(va_arg(arg, char *));
				i++;
			}
			else if (format[i + 1] == 'r')
			{
				count += _print_reverse(va_arg(arg, char *));
				i++;
			}
			else if (format[i + 1] == 'l')
			{
				count += print_long(va_arg(arg, unsigned long int), format[i + 2]);
				i = i + 2;
			}
			else if (format[i + 1] == 'h')
			{
				h = (unsigned short int)va_arg(arg, int);
				count += print_short(h, format[i + 2]);
				i = i + 2;
			}
			else if (format[i + 1] == 'p')
			{
				count += pointer(arg);
				i++;
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
