#ifndef __STDIO_H
#define __STDIO_H

#define EOF -1

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

screen_t curr_screen;

unsigned short screen_port_num;

int putchar(int c);
int putchar_help(int c, screen_t *scr);
int puts(const char *str);
void scroll(screen_t *scr);
void move_csr(screen_t *scr);
void cls(screen_t *scr);
void setcolor(unsigned int color, screen_t *scr);
int printf(const char *format, ...);
int sprintf(char *str, const char *format, ...);

#endif
