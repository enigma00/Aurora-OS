#include <string.h>

typedef struct gdt_entry
{
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char base_mid;
	unsigned char access;
	unsigned char gran;
	unsigned char base_high;
} __attribute__((packed)) gdt_entry_t;

struct gdt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

gdt_entry_t gdt[6];
struct gdt_ptr gp;

extern void gdt_flush();

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
	gdt[num].base_low = base & 0x0000FFFF;
	gdt[num].base_mid = (base & 0x00FF0000) >> 16;
	gdt[num].base_high = (base & 0xFF000000) >> 24;

	gdt[num].limit_low = (limit & 0xFFFF);
	gdt[num].gran = ((limit >> 16) & 0x0F);

	gdt[num].gran |= (gran & 0xF0);
	gdt[num].access = access;
}

void init_gdt()
{
	gp.limit = (sizeof(gdt_entry_t) * 6);
	gp.base = (unsigned int) &gdt;

	gdt_set_gate(0, 0, 0, 0, 0);
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	gdt_set_gate(3, 0, 0xC0000000, 0xBE, 0xEF);
	gdt_set_gate(4, 0, 0xC0000000, 0xBE, 0xEF);
	gdt_set_gate(5, 0, 0, 0, 0);

	gdt_flush();
}

typedef struct idt_entry
{
	unsigned short base_low;
	unsigned short sel;
	unsigned char zero;
	unsigned char flags;
	unsigned short base_high;
} __attribute__((packed)) idt_entry_t;

struct idt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

idt_entry_t idt[256];
struct idt_ptr idtp;

extern void idt_load();

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
	idt[num].base_low = base & 0x0000FFFF;
	idt[num].base_high = (base & 0xFFFF0000) >> 16;

	idt[num].sel = sel;
	idt[num].flags = flags;
}

void init_idt()
{
	idtp.limit = (sizeof(idt_entry_t) * 256) -1;
	idtp.base = (unsigned int) &idt;

	memset(&idt, 0, sizeof(idt_entry_t) * 256);

	idt_load();
}
