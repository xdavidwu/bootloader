SECTIONS
{
  . = 0x60000;
  __expected_start = .;
  .text : { *(.text) }
  . = ALIGN(8);
  .rodata : { *(.rodata) }
  . = ALIGN(8);
  .data : { *(.data) }
  . = ALIGN(8);
  __bss_start = .;
  .bss : { *(.bss) }
  __bss_end = .;
  __bss_size = __bss_end - __bss_start;
  __expected_end = .;
  __whole_size = __expected_end - __expected_start;
}
