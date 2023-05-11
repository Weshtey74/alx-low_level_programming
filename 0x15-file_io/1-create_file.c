#include "main.h"

/**
 * create_file - this function creates a file.
 * @filename: the pointer to name of the file to create.
 * @text_content: the pointer to a string to write to the file.
 *
 * Return: If the function fails  -1.
 *         Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fd, n, lenn = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenn = 0; text_content[lenn];)
			lenn++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	n = write(fd, text_content, lenn);

	if (fd == -1 || n == -1)
		return (-1);

	close(fd);

	return (1);
}
