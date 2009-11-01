#ifndef __X86_H
#define __X86_H

void inline outb(unsigned short port, unsigned char data)
{
	asm volatile("outb %1, %0" : : "dN" (port), "a" (data));
}

void inline inb(unsigned short port)
{
	unsigned char retval;
	asm volatile("inb %1, %0" : "=a" (retval) : "dN" (port));
	return retval;
}

#endif
