#PROG: objcopy
#objdump: -m mips:3000 -d --prefix-addresses --show-raw-insn
#name: MIPS1 negate instruction alias disassembly
#source: mips-neg-alias.s

.*: +file format .*mips.*

Disassembly of section \.text:
[0-9a-f]+ <[^>]*> 00010822 	neg	at,at
[0-9a-f]+ <[^>]*> 00021023 	negu	v0,v0
[0-9a-f]+ <[^>]*> 00041822 	neg	v1,a0
[0-9a-f]+ <[^>]*> 00053023 	negu	a2,a1
	\.\.\.
