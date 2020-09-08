CFLAGS += -ffreestanding -O2
LDFLAGS += -nostdlib

objects = boot.o main.o \
					../third_party/printf/printf.o

target = libosdev_bootstrap.bin

$(target): $(objects) linker.ld
	$(CC) $(CFLAGS) -o $@ $(objects) $(LDLIBS) $(LDFLAGS) -lgcc -T linker.ld
	grub-file --is-x86-multiboot2 $@

clean:
	rm -f $(objects) $(target)
