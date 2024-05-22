.text
	li $t0, 10
	li $t1, 2
	div $t0, $t1
	mflo $s0 #resultado da divisão inteiro
	mfhi $s1 #resto da divisão
	
	li $t0, 5
	li $t1, 2
	div $t0, $t1
	
	li $v0, 10
	syscall