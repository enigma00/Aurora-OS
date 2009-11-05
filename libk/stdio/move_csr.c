#include <stdio.h>
#include <x86.h>

void move_csr(screen_t *scr)
{
	unsigned temp = scr->csr_y * scr->height + scr->csr_x;

	outb(0x3D4, 14);
	outb(0x3D5, temp >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, temp);
}
