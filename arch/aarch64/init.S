_start:
	adr x1, #0
	mrs x4, mpidr_el1
	and x4, x4, 3
	cbz x4, cpu1
loop:
	wfe
	b loop
cpu1:
	ldr x4, =_start
	cmp x1, x4
	bne reloc
	mov sp, x4
	ldr x4, =__bss_start
	ldr x1, =__bss_end
clear_bss:
	str xzr, [x4], #8
	cmp x4, x1
	blo clear_bss
	ldr x1, =fdt
	str x0, [x1]
	bl machine_init
reloc:
	ldr x2, =__whole_size
	add x2, x2, x1
next:
	ldr x3, [x1], #8
	str x3, [x4], #8
	cmp x1, x2
	blo next
	ldr x4, =_start
	br x4
