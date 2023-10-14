#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

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
	return (lenght);
}

/**
 * _printf - A function that prints a formatted string
 * @format: the fisrt argument of a function
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i;
	int count = 0;
	va_start(arg, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(arg, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(arg, char *);
				int length = _strlen(str);
				write(1,str,length);
				count += length;
			}
			else if (format[i] == '%')
			{
				char p = '%';
				write(1, &p, 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		va_end(arg);
		return (count);
	}
