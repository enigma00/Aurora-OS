#include <stdio.h>
#include <x86.h>

void init_screen()
{
	if((inb(0x3CC) & 0x01) == 0)
	{
		screen_port_num = 0x3B4;
	}
	else
	{
		screen_port_num = 0x3D4;
		curr_screen.textptr = (unsigned short *) 0xC00B8000;
		curr_screen.attrib = 0x07;
		curr_screen.csr_x = 0;
		curr_screen.csr_y = 0;
		curr_screen.width = 80;
		curr_screen.height = 25;
	}
}
