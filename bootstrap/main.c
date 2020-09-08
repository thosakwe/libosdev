#include "../libosdev/libosdev.h"
#include "../third_party/printf/printf.h"
#define COM1 0x3f8
#define LIMIT_4GB 0xffffffff

osdev_gdtr_t gdtr;
osdev_gdt_entry_t gdt[3];

void _putchar(char ch) { osdev_outb(COM1, ch); }

void osdev_bootstrap_main(unsigned long magic, unsigned long addr) {
  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) {
    // TODO: Log improper magic
    printf("Invalid magic.\n");
    return;
  }

  // Set up a small GDT for the bootstrapper.
  printf("Setting up initial GDT.\n");
  printf("GDTR = %x, GDT = %x\n", &gdtr, &gdt);
  osdev_gdt_set_entry(&gdt[0], 0, 0, 0, 0);
  osdev_gdt_set_entry(&gdt[1], 0, LIMIT_4GB, 0x9a, 0xcf);
  osdev_gdt_set_entry(&gdt[2], 0, LIMIT_4GB, 0x92, 0xcf);
  gdtr.offset = (uint32_t)&gdt;
  gdtr.size = (sizeof(gdt) - 1);

  osdev_gdt_load((uint32_t)&gdtr, 0x10);

  printf("Setting up initial IDT.\n");

  // Search for a kernel module. If we find one, then load it.

  // Create the appropriate kind of page table.
  // Load the kernel as an ELF binary, and then map every page
  // into memory.
}
