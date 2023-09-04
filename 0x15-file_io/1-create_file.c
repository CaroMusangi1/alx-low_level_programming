#include "main.h"

/**
* create_file - Create or truncate a file and write text to it.
* @filename: Pointer to the file's name.
* @text_content: Pointer to the text to write (can be NULL).
*
* Return: On failure, -1. On success, 1.
*/
int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;

if (!filename)
return (-1);

if (text_content)
{
while (text_content[len])
len++;
}

fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(fd, text_content, len);

if (fd == -1 || w == -1)
return (-1);

close(fd);

return (1);
}
