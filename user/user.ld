/* OUTPUT_ARCH( "riscv" )
ENTRY( _entry ) */

SECTIONS
{
  /* . = 0x80002000; */
  /* . = 0x45002000; */

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
