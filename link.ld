OUTPUT_FORMAT(elf32-i386)
ENTRY(k_start)
SECTIONS
{
    . = 1M;
    .text BLOCK(4K) : ALIGN(4K)
    {
         *(.text)
    }
    .data : { *(.data) }
    .bss  : { *(.bss) }
    /DISCARD/:
    {
        *(.comment)
        *(.eh_frame)
    }
}