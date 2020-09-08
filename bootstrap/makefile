export ASFLAGS = $(CFLAGS)
export CFLAGS += -ffreestanding
export LDFLAGS += -nostdlib
LIBOSDEV = ../libosdev/libosdev.a

objects = boot.o main.o \
					../third_party/printf/printf.o

libs = $(LIBOSDEV)

target = libosdev_bootstrap.bin

.PHONY: $(LIBOSDEV)

$(target): $(objects) $(libs) linker.ld
	$(CC) $(CFLAGS) -T linker.ld -o $@ $(objects) $(libs) $(LDLIBS) $(LDFLAGS) -lgcc
	grub-file --is-x86-multiboot2 $@

$(LIBOSDEV):
	$(MAKE) -C ../libosdev

clean:
	rm -f $(objects) $(target)
	$(MAKE) -C ../libosdev clean
