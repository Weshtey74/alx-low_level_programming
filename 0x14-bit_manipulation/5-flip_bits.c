#include "main.h"

/**
 * flip_bits - this function returns the number of bits,
 * you would need to flip to get from one number to another
 * @n: this represents the first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int z, cont = 0;
	unsigned long int curr;
	unsigned long int exclusive = n ^ m;

	for (z = 63; z >= 0; z--)
	{
		curr = exclusive >> z;
		if (curr & 1)
			cont++;
	}

	return (cont);
}
