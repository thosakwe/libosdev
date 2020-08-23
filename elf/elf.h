#ifndef LIBOSDEV_ELF_ELF_H
#define LIBOSDEV_ELF_ELF_H
#include <stdint.h>

typedef struct {
  uint32_t program_entry_position;
  uint32_t program_header_table_offset;
  uint32_t section_header_table_offset;
  uint32_t flags;
  uint16_t header_size;
  uint16_t program_header_size;
  uint16_t program_header_count;
  uint16_t section_header_size;
  uint16_t section_header_count;
  uint16_t section_name_header_index;
} osdev_elf_header32_t;

typedef struct {
  uint64_t program_entry_position;
  uint64_t program_header_table_offset;
  uint64_t section_header_table_offset;
  uint32_t flags;
  uint16_t header_size;
  uint16_t program_header_size;
  uint16_t program_header_count;
  uint16_t section_header_size;
  uint16_t section_header_count;
  uint16_t section_name_header_index;
} osdev_elf_header64_t;

typedef struct {
  uint32_t magic;
  uint8_t bitness_flag;
  uint8_t endian_flag;
  uint8_t elf_header_version;
  uint8_t os_abi;
  uint64_t unused;
  uint16_t type;
  uint16_t instruction_set;
  uint32_t elf_version;
  union {
    osdev_elf_header32_t header32;
    osdev_elf_header64_t header64;
  };
} osdev_elf_header_t;

typedef enum {
  OSDEV_ELF_32_BIT = 1,
  OSDEV_ELF_64_BIT = 2
} osdev_elf_bitness_flag_t;

typedef enum {
  OSDEV_ELF_LITTLE_ENDIAN = 1,
  OSDEV_ELF_BIG_ENDIAN = 2
} osdev_elf_endian_flag_t;

typedef enum {
  OSDEV_ELF_TYPE_RELOCTABLE = 1,
  OSDEV_ELF_TYPE_EXECUTABLE = 2,
  OSDEV_ELF_TYPE_SHARED = 3,
  OSDEV_ELF_TYPE_CORE = 4,
} osdev_elf_type_t;

typedef enum {
  OSDEV_ELF_ISA_UNSPECIFIED = 0,
  OSDEV_ELF_ISA_SPARC = 2,
  OSDEV_ELF_ISA_X86 = 3,
  OSDEV_ELF_ISA_MIPS = 8,
  OSDEV_ELF_ISA_POWERPC = 0x14,
  OSDEV_ELF_ISA_ARM = 0x28,
  OSDEV_ELF_ISA_SUPERH = 0x2a,
  OSDEV_ELF_ISA_IA_64 = 0x32,
  OSDEV_ELF_ISA_X86_64 = 0x3e,
  OSDEV_ELF_ISA_AARCH64 = 0xb7,
} osdev_elf_isa_t;

#endif
