.global osdev_gdt_load32

.section .code
.code32

# (void* gdt, uint16 segment)
osdev_gdt_load32:
	mov 4(%esp), %eax
	mov 8(%esp), %ebx
	lgdt (%eax)
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
  mov %ebx, %cs
	ljmp *osdev_gdt_load32_done
osdev_gdt_load32_done:
	ret
