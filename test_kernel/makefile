export AS := i686-elf-as
export CC := i686-elf-gcc
export CFLAGS += -g

OSDEV_BOOTSTRAP = ../bootstrap/libosdev_bootstrap.bin
ISO = test_kernel.iso

.PHONY: $(OSDEV_BOOTSTRAP)

all: $(ISO)

clean:
	$(MAKE) -C ../bootstrap clean
	rm -f $(ISO)

$(ISO): $(OSDEV_BOOTSTRAP)
	rm -f $@
	mkdir -p isodir/boot
	cp $(OSDEV_BOOTSTRAP) isodir/boot/bootstrap.bin
	grub-mkrescue -o $@ isodir

$(OSDEV_BOOTSTRAP):
	$(MAKE) -C ../bootstrap

bochs: $(ISO)
	bochs -q -rc debug.rc

qemu: $(ISO)
	qemu-system-i386 -cdrom $< -no-reboot -no-shutdown -serial file:/dev/stdout
