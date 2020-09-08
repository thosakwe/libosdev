objects = x86/gdt.o x86/gdt_asm.o \
					../third_party/printf/printf.o

libosdev.a: $(objects)
	$(AR) rcs $@ $(objects)

clean:
	rm -f libosdev.a $(objects)
