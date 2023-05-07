#include "main.h"

/**
 * print_binary - this function prints the binary representation of a number
 * @n: the number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	int c, cont = 0;
	unsigned long int curr;

	for (c = 63; c >= 0; c--)
	{
		curr = n >> c;

		if (curr & 1)
		{
			_putchar('1');
			cont++;
		}
		else if (cont)
			_putchar('0');
	}
	if (!cont)
		_putchar('0');
}
