#PROG: objcopy
#objdump: -M no-aliases -m mips:3000 -d --prefix-addresses --show-raw-insn
#name: MIPS1 negate canonical alias disassembly
#source: mips-neg-alias.s

.*: +file format .*mips.*

Disassembly of section \.text:
[0-9a-f]+ <[^>]*> 00010822 	sub	at,zero,at
[0-9a-f]+ <[^>]*> 00021023 	subu	v0,zero,v0
[0-9a-f]+ <[^>]*> 00041822 	sub	v1,zero,a0
[0-9a-f]+ <[^>]*> 00053023 	subu	a2,zero,a1
	\.\.\.
