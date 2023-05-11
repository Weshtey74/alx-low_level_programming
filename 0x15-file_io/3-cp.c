#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - this function allocates 1024 bytes for a buffer
 * @file: name of the file buffer is storing chars for
 *
 * Return:the pointer to newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - this middle function closes the file descriptors
 * @fd: this is the file descriptor to be closed.
 */

void close_file(int fd)
{
	int z;

	z = close(fd);

	if (z == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this function copies the contents of a file to another file
 * @argv: the array pointers to the arguments
 * @argc: the number of arguments supplied to the program
 *
 * Return: 0 on success
 *
 * Description: should the argument count be incorrect - exit code 97
 * should file_from not exist or cannot be read - exit code 98
 * should file_to be unable to be created or written to - exit code 99
 * should file_to or file_from be incapable of closing - exit code 100
 */

int main(int argc, char *argv[])
{
	int fr, to, q, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_fr file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	fr = open(argv[1], O_RDONLY);
	q = read(fr, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || q == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read fr file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		m = write(to, buffer, q);
		if (to == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		q = read(fr, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (q > 0);

	free(buffer);
	close_file(fr);
	close_file(to);

	return (0);
}
