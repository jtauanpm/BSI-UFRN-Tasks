.data
	
	zero: .double 0.0

.text
	li $v0, 7
	syscall
	
	ldc1 $f2, zero
	add.d $f12, $f2, $f0
	
	li $v0, 3
	syscall
