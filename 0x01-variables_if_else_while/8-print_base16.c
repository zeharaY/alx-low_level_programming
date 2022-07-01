
#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase
 * Return:0
 */
int main(void)
{
		int i, y;
			for (i = 0; i < 10; i++)
					{
								putchar (i + '0');
									}
				for (y = 'a'; y <= 'f'; y++)
						{
									putchar (y);
										}

				putchar('\n');
				return (0);
}

