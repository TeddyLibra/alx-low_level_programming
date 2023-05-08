#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: is the name of the file 2create
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure and mull
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, byte_written, length_of = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length_of = 0; text_content[length_of];)
			length_of++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	byte_written = write(file_descriptor, text_content, length_of);

	if (file_descriptor == -1 || byte_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
