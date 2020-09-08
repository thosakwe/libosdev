#ifndef LIBOSDEV_GDT_H
#define LIBOSDEV_GDT_H
#include <stdint.h>

/**
 * A structure that allows you to more easily build a GDT.
 * By calling osdev_gdt_segment_to_long, you can build a
 * correct GDT, without doing a lot of cryptic bitwise operations.
 *
 * In addition, you can use osdev_gdt_long_to_segment to read entries
 * back into this structure.
 */
typedef struct {
  uint32_t base;
  uint32_t limit;
  uint8_t flags;
  uint8_t access;
} osdev_gdt_segment_t;

typedef struct {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed)) osdev_gdtr32_t;

typedef struct {
  uint16_t size;
  uint64_t offset;
} __attribute__((packed)) osdev_gdtr64_t;

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
 * Converts a GDT segment structure into an 8-byte GDT entry.
 */
uint64_t osdev_gdt_segment_to_long(osdev_gdt_segment_t *segment);

/**
 * Sets the values of a GDT entry.
 */
void osdev_gdt_set_entry(gdt_entry_t *entry, uint32_t base, uint32_t limit,
                         uint8_t access, uint8_t flags);

/**
 * Loads a 32-bit GDTR structure, and then jumps to the provided segment.
 */
extern void osdev_gdt_load32(osdev_gdtr32_t *gdt, uint16_t jump_to_segment);

#endif
