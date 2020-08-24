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

} osdev_gdt_segment_t;

typedef struct {
  uint16_t size;
  uint32_t offset;
} osdev_gdtr32_t;

typedef struct {
  uint16_t size;
  uint64_t offset;
} osdev_gdtr64_t;

/**
 * Converts a GDT segment structure into an 8-byte GDT entry.
 */
uint64_t osdev_gdt_segment_to_long(osdev_gdt_segment_t* segment);

/**
 * Converts an 8-byte GDT entry into a GDT segment structure.
 */
void osdev_gdt_long_to_segment(uint64_t entry, osdev_gdt_segment_t *segment);

/**
 * Loads a 32-bit GDTR structure, and then jumps to the provided segment.
 */
void osdev_gdt_load32(osdev_gdtr32_t* gdt,  uint16_t jump_to_segment);

/**
 * Loads a 64-bit GDTR structure, and then jumps to the provided segment.
 */
void osdev_gdt_load64(osdev_gdtr64_t* gdt,  uint16_t jump_to_segment);

#endif
