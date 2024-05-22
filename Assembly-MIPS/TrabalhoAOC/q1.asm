.data
quociente: .asciiz "Quociente = "
resto: .asciiz "Resto = "
space: .asciiz "\n"

.text
.main:
# scanf("%d", &dividendo); -> $t0 = dividendo (dividendo será salvo em $t0)
    li      $v0,    5
    syscall 
    move    $t0,    $v0

# scanf("%d", &divisor); -> $t1 = divisor (divisor será salvo em $t1)
    li      $v0,    5
    syscall 
    move    $t1,    $v0

# resto = dividendo; -> $t2 = resto (o resto será salvo em $t2 que é inicialmente igual a $t0(dividendo))
    move    $t2,    $t0

# quociente = 0; (quociente será salvo em $t3 e será inicialmente 0)
    move    $t3,    $zero

while:
    blt     $t2,    $t1,        end     # irá pular para "end" caso $t2(resto) < $t1(divisor)
    sub     $t2,    $t2,        $t1     # resto = resto - divisor;
    addi    $t3,    $t3,        1       # quociente++;
    j       while

end:                                    # irá fazer a impressão dos resultados na tela
                                        # Imprime a string "Quociente = "
    li      $v0,    4
    la      $a0,    quociente
    syscall 

# Imprime o valor de $t3 (quociente)
    li      $v0,    1
    move    $a0,    $t3
    syscall 

# Imprime quebra de linha "\n"
    li      $v0,    4
    la      $a0,    space
    syscall 

# Imprime a string "Resto = "
    li      $v0,    4
    la      $a0,    resto
    syscall 

# Imprime o valor de $t2 (resto)
    li      $v0,    1
    move    $a0,    $t2
    syscall 
    
# return 0;
    li      $v0,    10
    syscall                             
