#PROG: objcopy
#objdump: -M no-aliases -d --prefix-addresses --show-raw-insn
#name: microMIPS negate canonical alias disassembly
#source: micromips-neg-alias.s

.*: +file format .*mips.*

Disassembly of section \.text:
[0-9a-f]+ <[^>]*> 0020 0990 	sub	at,zero,at
[0-9a-f]+ <[^>]*> 0040 11d0 	subu	v0,zero,v0
[0-9a-f]+ <[^>]*> 0080 1990 	sub	v1,zero,a0
[0-9a-f]+ <[^>]*> 00a0 31d0 	subu	a2,zero,a1
	\.\.\.
