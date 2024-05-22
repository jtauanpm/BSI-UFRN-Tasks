.data
par: .asciiz "Par\n"
impar: .asciiz "Impar\n"
.text
.main:
# scanf("%d", &numero);
    li      $v0,            5
    syscall 
    move    $a0,            $v0

# divisor = 2
    li      $a1,            2

# resto = resto_divisao(numero, 2); Chamada da função (O retorno estará em $v0)
    jal     resto_divisao

# if(resto == 0) Caso resto seja 0, irá pular para a label print_par ($v0 terá o retorno da função)
    beq     $v0,            $zero,  print_par

# printf("Impar\n");
    li      $v0,            4
    la      $a0,            impar
    syscall 
    j       end

# printf("Par\n");
print_par:
    li      $v0,            4
    la      $a0,            par
    syscall 
    j       end

end:                                            # bloco que encerra o programa
    li      $v0,            10
    syscall                                     # return 0;

resto_divisao:
# resto ($t0) = dividendo (o dividendo será passado como paramêtro em $a0);
    move    $t0,            $a0

# quociente = 0; O quociente será $t1
    move    $t1,            $zero

while:
# o divisor será passado como paramêtro em $a0
    blt     $t0,            $a1,    return      # Se o resto ($t0) for menor que o divisor ($a0) retorne o resto
    sub     $t0,            $t0,    $a1         # resto = resto - divisor;
    addi    $t1,            $t1,    1           # quociente++;
    j       while
return:                                         # return resto;
    move    $v0,            $t0                 # retorna o resto em $v0
    jr      $ra

