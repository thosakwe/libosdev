#ifndef LIBOSDEV_GDT_H
#define LIBOSDEV_GDT_H
#include <stdint.h>

typedef struct {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed)) osdev_gdtr_t;

/**
 * The actual x86 GDT structure.
 */
typedef struct {
  uint16_t limit_0_15;
  uint16_t base_0_15;
  uint8_t base_16_23;
  uint8_t access;
  uint8_t limit_16_19_and_flags;
  uint8_t base_24_31;
} __attribute__((packed)) gdt_entry_t;

/**
 * Sets the values of a GDT entry.
 */
void osdev_gdt_set_entry(gdt_entry_t *entry, uint32_t base, uint32_t limit,
                         uint8_t access, uint8_t flags);

/**
 * Loads a 32-bit GDTR structure, and then jumps to the provided segment.
 */
extern void osdev_gdt_load(uint32_t gdtr_ptr, uint16_t jump_to_segment);

#endif
