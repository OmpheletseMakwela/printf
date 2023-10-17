#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int hexadecimal(int n)
{
	char arr[] = "0123456789ABCDEF";
	char *storage = '\0';
	int count = 0;
	int num_char =  n;
	int i;
	int r;

	if (n == 0)
	{
		char c = '0';
		write(1, &c, 1);
	}
	while (num_char > 0)
	{
		num_char /= 16;
		count++;
	}
	storage = (char *)malloc(count + 1);

	for (i = 0; i < count; i++)
	{
		r = n % 16;
		storage[count - 1 - i] = arr[r];
		n /= 16;
	}
	storage[count] = '\0';
	write(1, storage, count);
	free(storage);

	return (count);
}
