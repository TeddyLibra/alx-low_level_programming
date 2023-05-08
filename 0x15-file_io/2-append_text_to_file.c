#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: is d name of file
 * @text_content: The string to add to the end of the file.
 * Return: 1 on success and file exists, -1 on failure, null and
 * if the file does not exist or if you do not have the required
 * permissions to write the file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int open_f, bytes_written, length_of = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length_of = 0; text_content[length_of];)
			length_of++;
	}

	open_f = open(filename, O_WRONLY | O_APPEND);
	w = write(open_f, text_content, length_of);

	if (open_f == -1 || bytes_written == -1)
		return (-1);

	close(open_f);

	return (1);
}
