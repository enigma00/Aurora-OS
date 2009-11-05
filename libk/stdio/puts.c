#include <stdio.h>
#include <string.h>

int puts(const char *str, screen_t *scr)
{
	unsigned int i;

	for (i=0; i < strlen(str); i++)
	{
		putchar(str[i], scr);
	}
	return 0;
}

int puts_helper(const char *str)
{
	unsigned int i;


	for (i=0; i < strlen(str); i++)
	{
		putchar_helper(str[i]);
	}
	return 0;
}
