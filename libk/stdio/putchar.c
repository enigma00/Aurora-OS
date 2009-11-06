#include <stdio.h>

int putchar_help(int c, screen_t *scr)
{
	switch (c)
	{
		case 0x08:
			if (scr->csr_x <= 0)
			{
				scr->csr_x = 0;
			}
			else
			{
				scr->csr_x--;
			}
			break;
		case 0x09:
			scr->csr_x = (scr->csr_x + 8) & ~(8 - 1);
			break;
		case '\r':
			scr->csr_x = 0;
			break;
		case '\n':
			scr->csr_x = 0;
			scr->csr_y++;
			break;
		default:
			scr->textptr[scr->csr_y * scr->width + scr->csr_x] = (((unsigned char) (c & 0xFF)) | (scr->attrib << 8));
			scr->csr_x++;
	}
	if ((unsigned )scr->csr_x >= scr->width)
	{
		scr->csr_x = 0;
		scr->csr_y++;
	}

	scroll(scr);
	if (scr == &curr_screen)
	{
		move_csr(scr);
	}
	return c;
}

int putchar(int c)
{
	return putchar_help(c, &curr_screen);
}
