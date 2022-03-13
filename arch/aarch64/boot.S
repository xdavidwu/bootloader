	.global boot
	.type boot, %function
boot:
	ldr x1, =fdt
	ldr x0, [x1]
	ldr x1, =0x80000
	br x1
