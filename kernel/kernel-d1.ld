/* OUTPUT_ARCH( "riscv" ) */
ENTRY( _entry )

SECTIONS
{
  . = 0x45000000;

  .text : {
    *(.text)
  }
  . = ALIGN(4K);
    
  .data : {
    *(.data .data.*)
  }
  . = ALIGN(4K);

  .bss : {
    *(.bss .bss.*)
  }
}
