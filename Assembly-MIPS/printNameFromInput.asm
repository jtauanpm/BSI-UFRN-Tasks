.data
	inputMsg: .asciiz "Digite seu nome: "
	outputMsg: .asciiz "Olá, "
	name: .space 30

.text
	la $a0, inputMsg
	li $v0, 4
	syscall
	
	la $a0, name
	la $a1, 30
	li $v0, 8
	syscall
	move $t0, $a0
	
	la $a0, outputMsg
	li $v0, 4
	syscall
	
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
