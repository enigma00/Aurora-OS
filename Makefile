CC := i586-elf-gcc
LD := i586-elf-ld
AS := nasm
AUXFILES := Makefile linker.ld
PROJDIRS := src inc lib
SRCFILES := $(shell find $(PROJDIRS) -mindepth 1 -maxdepth 3 -name "*.c")
HDRFILES := $(shell find $(PROJDIRS) -mindepth 1 -maxdepth 3 -name "*.h")
ASMFILES := $(shell find $(PROJDIRS) -mindepth 1 -maxdepth 3 -name "*.asm")
OBJFILES := $(patsubst %.asm, %.o, $(ASMFILES)) $(patsubst %.c, %.o, $(SRCFILES))
DEPFILES := $(patsubst %.c, %.d, $(SRCFILES))
ALLFILES := $(SRCFILES) $(HDRFILES) $(ASMFILES) $(AUXFILES)

CFLAGS := -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs -ffreestanding

.PHONY: all clean dist todolist test

all: aurora.iso

aurora.iso: kernel.bin
	@cp kernel.bin ../isofiles/boot
	@genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -quiet -boot-load-size 4 -boot-info-table -o aurora.iso ../isofiles

kernel.bin: $(OBJFILES)
	@$(LD) -T linker.ld $(OBJFILES) -o kernel.bin

test: aurora.iso
	@qemu -cdrom aurora.iso -net none -s

debug:
	gdb

clean:
	-@$(RM) $(wildcard $(OBJFILES) $(DEPFILES) kernel.bin aurora.iso *~)

todolist:
	-@for file in $(ALLFILES); do fgrep -H -e TODO -e FIXME $$file; done; true

%.o: %.c
	@$(CC) $(CFLAGS) -g -I./inc -c $< -o $@

%.o: %.asm
	@$(AS) -f elf $< -o $@
