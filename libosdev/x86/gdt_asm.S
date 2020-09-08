.global osdev_gdt_load

.section .text
.code32

# (void* gdt, uint32 code_seg, uint32 data_seg)
osdev_gdt_load:
  xchgw %bx, %bx
  mov 4(%esp), %eax # void * gdt
  mov 8(%esp), %ecx # uint32 data_seg
  xchgw %bx, %bx
	lgdt (%eax)
  # No longer need to overwrite ax
	# mov $0x10, %ax
	mov %cx, %ds
	mov %cx, %es
	mov %cx, %fs
	mov %cx, %gs
	mov %cx, %ss
	ljmp $0x08, $osdev_gdt_load_done
osdev_gdt_load_done:
	ret
