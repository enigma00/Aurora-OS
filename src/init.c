#include <init.h>
#include <stdio.h>

void init()
{
	init_screen();
	init_gdt();
	for(;;);
}
