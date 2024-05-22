.data
	resultmsg: .asciiz "Sua idade é:" 
	inputmsg: .asciiz "Digite sua idade: " 

.text
	la $a0, inputmsg 
	li $v0, 4
	syscall #chama a função que está em $v0 e imrpime na tela a menasgem em $a0
	
	li $v0, 5
	syscall #chama a função que está em $v0 e recebe inteiro em $v0
	move $t0, $v0 
	
	la $a0, resultmsg
	li $v0, 4
	syscall #chama a função que está em $v0 e imrpime na tela a menasgem em $a0
	
	li $v0, 1
	move $a0, $t0
	syscall #chama a função que está em $v0 e imrpime na tela o inteiro em $a0
	
	li $v0, 10 #encerra o programa
	syscall