#include <string.h>
#include <stdio.h>

void cls_help(screen_t *screen)
{
	memset(screen->textptr, (screen->textptr + screen->width * screen->height * screen->depth), 0);
}

void cls()
{
	cls_help(current);
}
