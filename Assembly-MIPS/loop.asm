.data
	msg: .asciiz "Digite um número: "
	space: .byte ' '

.text
	#Recebe um int e imprime os valores de 0 até o int
	li $v0, 4
	la $a0, msg
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	move $t1, $zero
	
	while:
		bgt $t1, $t0, end
		
		li $v0, 1
		move $a0, $t1
		syscall
		
		li $v0, 4
		la $a0, space
		syscall
		
		addi $t1, $t1, 1
		j while
		
	end:
		li $v0, 10
		syscall
