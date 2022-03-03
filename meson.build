project('osdikern', 'c')

sources = [
  'arch/aarch64/init.S',
  'arch/aarch64/boot.S',
  'arch/aarch64/machines/rpi3.c',
  'uart/bcm2835_mini_uart.c',
  'uart/bcm2835_mini_uart.S',
  'init.c',
]

elf = executable('kernel8.elf',
  sources,
  c_args: '-ffreestanding',
  link_args: ['-nostdlib', '-T', join_paths(meson.current_source_dir(), 'arch/aarch64/linker.ld')],
  include_directories: include_directories('include')
)

objcopy = find_program(meson.get_external_property('prefix') + 'objcopy')

custom_target('rpi3-image',
  output: 'kernel8.img',
  input: elf,
  command: [objcopy, '-O', 'binary', '@INPUT@', '@OUTPUT@'],
  build_by_default: true,
)

executable('send-kernel', 'host/send-kernel.c', native: true)
