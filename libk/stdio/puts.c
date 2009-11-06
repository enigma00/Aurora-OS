#include <stdio.h>
#include <string.h>

int puts_help(const char *str, screen_t *scr)
{
	unsigned int i;

	for (i=0; i < strlen(str); i++)
	{
		putchar_help(str[i], scr);
	}
	return 0;
}

int puts(const char *str)
{
	return puts_help(str, &curr_screen);
}
