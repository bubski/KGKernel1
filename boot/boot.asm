	BITS 32

global k_start

extern k_main

dd 0x1BADB002
dd 0x00
dd - (0x1BADB002 + 0x00)

k_start:
	call k_main

	hlt