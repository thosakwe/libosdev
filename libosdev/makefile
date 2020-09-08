objects = x86/gdt.o x86/gdt_asm.o

libosdev.a: $(objects)
	$(AR) rcs $@ $(objects)

clean:
	rm -f libosdev.a $(objects)
