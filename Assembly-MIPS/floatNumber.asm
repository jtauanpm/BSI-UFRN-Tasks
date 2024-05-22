.data
	
	zero: .float 0.0

.text
	li $v0, 6
	syscall
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f0
	
	li $v0, 2
	syscall
	
	li $v0, 10
	syscall
