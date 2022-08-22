#include "main.h"

/**
 * create_file - creates and writes in a file
 * @filename: the file name
 * @text_content: content
 *
 * Return: 1 or -1 
 */
int create_file(const char *filename, char *text_content)
{
	int fd, x, y = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[y])
			y++;
		x = write(fd, text_content, y);
		if (x != y)
			return (-1);
	}

	close(fd);

	return (1);
}
