.data
	array:
		.align 2
		.space 16
	
.text
.main:
	move $t0, $zero #indice do array
	move $t1, $zero #valor a ser colocado no array
	
	li $t2, 16 #Tamanho do array
	
	loop:
		beq $t0, $t2, end
		sw $t1, array($t0)
		addi $t1, $t1, 1
		addi $t0, $t0, 4
		j loop
		
	end:
		move $t0, $zero
		imprime:
			beq $t0, $t2, endAll
			lw $a0, array($t0)
			addi $t0, $t0, 4
			li $v0, 1
			syscall
			j imprime
			
		endAll:
			li $v0, 10
			syscall
		