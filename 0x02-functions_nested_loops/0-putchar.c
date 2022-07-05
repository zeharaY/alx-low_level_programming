#include "main.h"
#include <unistd.h>
/**
 * main : prints _putchar
 *
 * Return : returns zero
 */
int _putchar (char c)
{
	return (write(1, &c, 1));
}
