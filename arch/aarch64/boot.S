	.global boot
	.type boot, %function
boot:
	ldr x0, =0x80000
	br x0
