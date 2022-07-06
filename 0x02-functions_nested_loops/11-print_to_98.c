#include "main.h"

/**
 * print_to_98 - check the code
 * @n : parameter
 *
 * Return: Always 0.
 */

void print_to_98(int n)
{
	int i = 0;

	if (n > 98)
	{
		for (i = n; i >= 98; i--)
		{
			if (i != n)
			{
				printf(", ");
			}
			printf("%d", i);
		}
	}
	else
	{
		for (i = n; i <= 98 ; i++)
		{
			if (i != n)
			{
				printf(", ");
			}
			printf("%d", i);
		}
	}
	putchar('\n');
}
