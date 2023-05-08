#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_content_file(char *the_file);
void close_content_file(int file_descriptor);

/**
 * create_content_file - create 1024 bytes 4content file.
 * @the_file: content
 * Return: A pointer variable 2new content_file
 */
char *create_content_file(char *the_file)
{
	char *content_file;

	content_file = malloc(sizeof(char) * 1024);

	if (content_file == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", the_file);
		exit(99);
	}

	return (content_file);
}

/**
 * close_content_file - a function 2close d descriptor
 * @file_descriptor: D descriptor
 */
void close_content_file(int file_descriptor)
{
	int close_f;

	close_f = close(file_descriptor);

	if (close_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - a function that cp d contents of a file 2another
 * @argc: D arguments
 * @argv: point to the argmnt.
 * Return: 0 (success)
 * Description: exit code 97 if its correct
 * exit code 98 if it\'s not read.
 * exit code 99 if can\'t b crea or wri
 * exit code 100 if it isn't closed
 */
int main(int argc, char *argv[])
{
	int frm_f, to_f, read_f, bytes_written;
	char *content_file;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	content_file = create_content_file(argv[2]);
	frm_f = open(argv[1], O_RDONLY);
	read_f = read(frm_f, content_file, 1024);
	to_f = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (frm_f == -1 || read_f == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(content_file);
			exit(98);
		}

		bytes_written = write(to_f, content_file, read_f);
		if (to_f == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(content_file);
			exit(99);
		}

		r = read(frm_f, content_file, 1024);
		to_f = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_f > 0);

	free(content_file);
	close_content_file(frm_f);
	close_content_file(to_f);

	return (0);
}
