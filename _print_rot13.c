#include "main.h"
/**
 * _print_rot23 - prints the rot13'ed string.
 *@r: string
 *Return: number of characters printed.
 */
int _print_rot23(char *r)
{
	int num, i, count = 0;

	for (i = 0; r[i] != '\0'; i++)
	{
		num = r[i];
		if ((num >= 65 && num <= 77) || (num >= 97 && num <= 109))
		{
			num += 13;
			_putchar(num);
			count++;
		}
		else if ((num >= 97 && num <= 109) || (num >= 110 && num <= 122))
		{
			num -= 13;
			_putchar(num);
			count++;
		}
		else
		{
			_putchar(r[i]);
			count++;
		}
	}
	return (count);
}
