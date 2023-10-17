#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * pointer - prints the address of a variable
 * @arg: 1st parameter
 */
int pointer(va_list arg)
{
	char buffer[1024];
	unsigned long num = (unsigned long)va_arg(arg, void *);
	int charCount = 0;
	int value;
	int i;
	int count = 0;

	while (num > 0)
	{
		value = num % 16;
		buffer[charCount++] = (value < 10) ? ('0' + value) : ('a' + value - 10);
		num /= 16;
	}
	buffer[charCount++] = 'x';
	buffer[charCount++] = '0';

	for (i = charCount - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}
