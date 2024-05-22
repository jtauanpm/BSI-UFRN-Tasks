.data
	impar: .asciiz "É ímpar"
	par: .asciiz "É par"
	input: .asciiz "Digite um número: "

.text
	li $v0, 4
	la $a0, input
	syscall
	
	li $v0, 5
	syscall
	
	li $t0, 2
	div $v0, $t0
	
	mfhi $t1
	
	beq $t1, $zero, imprimePar
	
	li $v0, 4
	la $a0, impar
	syscall
	
	li $v0, 10
	syscall
	
	imprimePar:
		li $v0, 4
		la $a0, par
		syscall
		
	li $v0, 10
	syscall