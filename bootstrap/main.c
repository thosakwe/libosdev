#include "../libosdev/libosdev.h"
#include "../third_party/printf/printf.h"
#define COM1 0x3f8

void _putchar(char ch) { osdev_outb(COM1, ch); }

void osdev_bootstrap_main(unsigned long magic, unsigned long addr) {
  if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
    // TODO: Log improper magic
    printf("Invalid magic.\n");
    return;
  }

  printf("WE MADE IT\n");

  // Search for a kernel module. If we find one, then load it.

  // Create the appropriate kind of page table.
  // Load the kernel as an ELF binary, and then map every page
  // into memory.
}
