#include "main.h"

/**
 * readFile - Function to read keyboard input
 * @file: keyboard input
 * @buffer: to store input
 * @count: to keep track of input digits
 *
 * Return: number of characters read
 */

ssize_t readFile(int file, void *buffer, size_t count)
{
	ssize_t bytesRead;

	bytesRead = read(file, buffer, count);
	if (bytesRead == -1)
	{
		perror("read");
	}
	return (bytesRead);
}
