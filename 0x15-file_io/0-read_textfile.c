#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Write a function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: the file that will be read
 * @letters: num of letters 2b read
 * Return: actual number of letters it could read and print
 * if the file can not be opened or read,Null, write fail or 
 * does not write the expexted amount of bytes, retun 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *file_content;
	ssize_t file_descriptor;
	ssize_t byte_written;
	ssize_t store_num_byte;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	file_content = malloc(sizeof(char) * letters);
	store_num_byte = read(file_descriptor, buf, letters);
	byte_written = write(STDOUT_FILENO, file_content, store_num_byte);

	free(file_content);
	close(file_descriptor);
	return (byte_written);
}
