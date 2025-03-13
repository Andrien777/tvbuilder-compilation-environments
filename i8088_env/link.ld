SECTIONS
{
  .bootSegment 0xFF0 : {KEEP(*(.text.bootloader))}
  .baseSegment 0x000 : {KEEP(*(.entry)) *(.text.*)}
  .data 0x500 : {KEEP(*(.data))}
}
entry = 0;
ENTRY(entry)
