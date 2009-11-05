#include <stdio.h>
#include <string.h>

void scroll(screen_t *scr)
{
	if ((unsigned) scr->csr_y >= scr->height)
	{
		memcpy(scr->textptr, scr->textptr + (scr->csr_y - scr->height + 1) * scr->width, (scr->height - (scr->csr_y - scr->height + 1)) * scr->width * 2);
		memset(scr->textptr + (scr->height - (scr->csr_y - scr->height + 1)) * scr->width, 0, scr->width * 2);
		scr->csr_y = scr->height - 1;
	}
}
