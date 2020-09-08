export CC := i686-elf-gcc

OSDEV_BOOTSTRAP = ../bootstrap/libosdev_bootstrap.bin
ISO = test_kernel.iso

.PHONY: $(OSDEV_BOOTSTRAP)

all: $(ISO)

clean:
	$(MAKE) -C ../bootstrap clean

$(ISO): $(OSDEV_BOOTSTRAP)
	rm -f $@
	mkdir -p isodir/boot
	cp $(OSDEV_BOOTSTRAP) isodir/boot/bootstrap.bin
	grub-mkrescue -o $@ isodir

$(OSDEV_BOOTSTRAP):
	$(MAKE) -C ../bootstrap

qemu: $(ISO)
	qemu-system-i386 -cdrom $< -no-reboot -no-shutdown -serial file:/dev/stdout
