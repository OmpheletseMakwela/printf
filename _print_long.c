#include "main.h"
/**
 * print_long - prints interger with a modified length.
 * @i: interger
 * @s: specifier
 * Return: length of what is printed.
 */
int print_long(unsigned long int i, char s)
{
	unsigned int count = 0;
	signed short int d = (signed short)i;

	if (s == 'd' || s == 'i')
		count += _printdigit(d);
	else if (s == 'o')
		count += _print_octal(i);
	else if (s == 'u')
		count += _print_unsigned(i);
	else if (s == 'x')
		count += hex(i);
	else if (s == 'X')
	    count += hexadecimal(i); 
	return (count);    
}
