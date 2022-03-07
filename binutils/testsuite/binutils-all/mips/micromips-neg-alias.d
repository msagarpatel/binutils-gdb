#PROG: objcopy
#objdump: -d --prefix-addresses --show-raw-insn
#name: microMIPS negate instruction alias disassembly
#source: micromips-neg-alias.s

.*: +file format .*mips.*

Disassembly of section \.text:
[0-9a-f]+ <[^>]*> 0020 0990 	neg	at,at
[0-9a-f]+ <[^>]*> 0040 11d0 	negu	v0,v0
[0-9a-f]+ <[^>]*> 0080 1990 	neg	v1,a0
[0-9a-f]+ <[^>]*> 00a0 31d0 	negu	a2,a1
	\.\.\.
