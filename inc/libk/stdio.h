#ifndef __STDIO_H
#define __STDIO_H

#define EOF -1
#define NULL (void*)0

typedef struct screen
{
	unsigned short *textptr;
	unsigned int attrib;
	int csr_x;
	int csr_y;
	int esc1;
	int esc2;
	int esc3;
	unsigned int width;
	unsigned int height;
} screen_t;

screen_t *current;

int putchar(int c, screen_t *scr);
int puts(const char *str, screen_t *scr);
void scroll(screen_t *scr);
void move_csr(screen_t *scr);
void cls(screen_t *scr);
void setcolor(unsigned int color, screen_t *scr);

#endif
