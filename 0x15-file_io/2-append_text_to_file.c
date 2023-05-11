#include "main.h"

/**
 * append_text_to_file - this function appends text at the end of a file
 * @filename: the pointer to the name of the file
 * @text_content: the string to be added to the end of the file
 *
 * Return: If the function fails or filename is NULL - -1
 *         If the file does not exist the user lacks write permissions -1
 *         Otherwise - 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, n, lenn = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenn = 0; text_content[lenn];)
			lenn++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	n = write(o, text_content, lenn);

	if (o == -1 || n == -1)
		return (-1);

	close(o);

	return (1);
}
