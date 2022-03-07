	.text
	.set	mips32r3
	.set	noat
	.set	micromips
foo:
	neg	$1
	negu	$2
	neg	$3, $4
	negu	$6, $5

# Force some (non-delay-slot) zero bytes, to make 'objdump' print ...
	.align	4, 0
	.space	16
