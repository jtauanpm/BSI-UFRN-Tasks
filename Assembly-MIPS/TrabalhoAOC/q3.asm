.text
main:
# scanf("%d", &base);
    li      $v0,    5
    syscall 
    move    $a0,    $v0                 # a base será representada por $a0

# scanf("%d", &expoente);
    li      $v0,    5
    syscall 
    move    $a1,    $v0                 # o expoente será representado por $a1

# resultado = power(base, expoente);
    jal     power
    move    $a0,    $v0                 # o retorno de power estará em $v0

# printf("%d\n", resultado);
    li      $v0,    1
    syscall 

# return 0;
    li      $v0,    10
    syscall 

power:
# abre espaço na pilha para salvar o $ra (endereço de retorno)
    addi    $sp,    $sp,    -4
    sw      $ra,    0($sp)

# se expoente for diferente de 0, pula para o recursiva
    bne     $a1,    $zero,  recursiva

# resultado = 1; return resultado; (caso base)
    addi    $v0,    $zero,  1

# incrementa pilha
    addi    $sp,    $sp,    4

    jr      $ra                         # retorna ao endereço salvo em $ra
recursiva:
    bne     $a1,    1,      else        # se expoente != 1, pula para else
    add     $v0,    $zero,  $a0         # retorna a própria base
    addi    $sp,    $sp,    4           # incrementa a pilha

    jr      $ra                         # retorna ao endereço salvo em $ra
else:
    move    $t1,    $a1			# move o expoente para $t1
    andi    $t0,    $t1,    1           # verifica se o expoente é negativo ou positivo
    bne     $t0,    $zero,  else2       # se negativo, pula para else2
    srl     $a1,    $a1,    1           # se positivo, divide o expoente por 2
    jal     power                       # chama a função recursiva
    mul     $v0,    $v0,    $v0         # multiplica os valores de retorno
    lw      $ra,    0($sp)              # carrega o endereço de retorno ($ra) da pilha
    addi    $sp,    $sp,    4           # incrementa a pilha
    jr      $ra                         # retorna ao endereço salvo em $ra
else2:
    addi    $a1,    $a1,    -1          # subtrai -1 do expoente
    jal     power                       # chama a função recursiva
    lw      $ra,    0($sp)              # carrega o endereço de retorno ($ra) da pilha
    addi    $sp,    $sp,    4           # incrementa a pilha
    mul     $v0,    $v0,    $a0         # multiplica o valore de retorno com a base
    jr      $ra                         # retorna ao endereço salvo em $ra
