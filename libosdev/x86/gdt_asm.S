.global osdev_gdt_load

.section .data
msg:
.ascii "What the fuck?\n"

.section .code
.code32

# (void* gdt, uint16 segment)
osdev_gdt_load:
  ret
	mov 4(%esp), %eax
	mov 8(%esp), %ebx
  xchgw %bx, %bx
	lgdt (%eax)
	mov $0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
  mov %bx, %cs
	ljmp *osdev_gdt_load_done
osdev_gdt_load_done:
	ret
