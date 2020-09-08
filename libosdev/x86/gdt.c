#include "gdt.h"

void osdev_gdt_set_entry(gdt_entry_t *entry, uint32_t base, uint32_t limit,
                         uint8_t access, uint8_t flags) {
  entry->base_0_15 = base & 0xffff;
  entry->base_16_23 = (base >> 16) & 0xff;
  entry->base_24_31 = (base >> 24) & 0xff;

  // Set the access
  entry->access = access;

  // Set the limit
  entry->limit_0_15 = limit & 0xffff;

  // Set the flags
  entry->limit_16_19_and_flags = (limit >> 16) & 0x0f;
  entry->limit_16_19_and_flags |= (flags & 0xf0);
}
