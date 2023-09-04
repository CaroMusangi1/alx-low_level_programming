#include "main.h"

/**
* append_text_to_file - Append text to the end of a file.
* @filename: Pointer to the file's name.
* @text_content: Pointer to the text to add (can be NULL).
* Return: On failure or if filename is NULL - -1. Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int o, w, len = 0;

if (!filename)
return (-1);

if (text_content)
{
while (text_content[len])
len++;
}

o = open(filename, O_WRONLY | O_APPEND);
w = write(o, text_content, len);

if (o == -1 || w == -1)
return (-1);

close(o);

return (1);
}
