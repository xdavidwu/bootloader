_start:
	adr x1, #0
	mrs x0, mpidr_el1
	and x0, x0, 3
	cbz x0, cpu1
loop:
	wfe
	b loop
cpu1:
	ldr x0, =_start
	cmp x1, x0
	bne reloc
	mov sp, x0
	ldr x0, =__bss_start
	ldr x1, =__bss_end
clear_bss:
	str xzr, [x0], #8
	cmp x0, x1
	blo clear_bss
	bl machine_init
reloc:
	ldr x2, =__whole_size
	add x2, x2, x1
next:
	ldr x3, [x1], #8
	str x3, [x0], #8
	cmp x1, x2
	blo next
	ldr x0, =_start
	br x0
