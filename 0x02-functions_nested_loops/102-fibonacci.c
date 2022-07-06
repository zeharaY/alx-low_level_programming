#include <stdio.h>
/**
 * main - fibonacci 5
 * Return: 0 always Success
 */

int main(void)
{
	unsigned long int i;
	unsigned long int bef = 1;
	unsigned long int aft = 2;

	printf("%lu", bef);

	for (i = 1; i < 50; i++)
	{
		printf(", %lu", aft);
		aft += bef;
		bef = aft - bef;
	}
	printf("\n");
	return (0);
}
