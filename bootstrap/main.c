#include "../elf/elf.h"
#include "../multiboot2.h"

void osdev_bootstrap_main(unsigned long magic, unsigned long addr) {
  if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
    // TODO: Log improper magic
    return;
  }

	// Search for a kernel module. If we find one, then load it.
	
	// Create the appropriate kind of page table.
	// Load the kernel as an ELF binary, and then map every page
	// into memory.
}
