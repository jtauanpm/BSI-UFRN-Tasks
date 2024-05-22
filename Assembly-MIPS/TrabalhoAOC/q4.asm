.data

space1: ' '
space: '\n'

.text
.globl main
main:
    li      $t1,            0               #p = 0; p será representado por $t1
    
#scanf("%d", &len); o tamanho do vetor será representado por $s7
    li      $v0,            5
    syscall 
    move    $s7,            $v0
#a = (int*)malloc(sizeof(int)*len); 
#for(int i = 0; i < len; i++){
#scanf("%d", &(a[i]));
    jal     readVet 
    jal     space_ #print quebra de linha
    
#printVetor(a, len);
    jal     printVet
    jal     space_
    
#ord(p, a, len);
    move    $a0,            $t1             # t1 armazena o valor de p
    move    $a2,            $s7             # s7 armazena o tamanho do vetor
    jal     order
    
#printVetor(a, len);
    jal     printVet
    
#return 0;
    li      $v0,            10
    syscall 

space_:
    la      $a0,            space
    li      $v0,            4
    syscall 
    jr      $ra

printVet:
    li      $s1,            0               #$s1 será o índice
loop:
    bge     $s1,            $s7,    else
    sll     $s2,            $s1,    2
    addu    $t0,            $s0,    $s2
    li      $v0,            4
    la      $a0,            space1
    syscall 
    lw      $a0,            ($t0)
    li      $v0,            1
    syscall 
    addi    $s1,            $s1,    1
    j       loop

else:
    jr      $ra

readVet:
#sabendo que um inteiro ocupa 4 bytes, multiplicamos o tamanho por quatro (ou deslocamos duas casas a esquerda) para obter o tamanho do vetor em bytes
    sll     $t4,            $s7,    2
    
#solicita espaço de memória na heap ao sistema, passando como parâmentro ($a0) o tamanho do vetor ($t4) 
    move    $a0,            $t4
    li      $v0,            9
    syscall 
    move    $s0,            $v0             # $s0 armazena o endereço base do vetor

    li      $s1,            0               # $s1 controlará o índice do vetor, inicialmente 0

loop2:
    bge     $s1,            $s7,    else #enquanto o índice não é maior que o tamanho
# lê valor 
    li      $v0,            5
    syscall 
# armazena os elementos lidos na memória alocada
    sll     $t3,            $s1,    2 #multiplicando o valor do índice por 4 para obter o valor do offset do endereço do vetor
    addu    $a1,            $s0,    $t3 # soma o endereço base do vetor com o offset
    sw      $v0,            ($a1) #armazena o valor lido na posição do vetor
    addi    $s1,            $s1,    1 #incrementa o índice
    j       loop2

order:
#$a0 armazena o valor de p, $a1 armazena o endereço inicial do vetor, $a2 armazena o tamanho do vetor
#Abre espaço na pilha e armazenar o valor do endereço de retorno ($ra)	
    addi    $sp,            $sp,    -4
    sw      $ra,            0($sp)
    
    bge     $a0,            $a2,    return #verifica se o valor de p é maior igual a ao tamanho do vetor
    add     $a3,            $a0,    $zero   #$a3 irá representar o índice 
    jal     loop3
    addi    $a0,            $a0,    1
    jal     order

return:
    lw      $ra,            0($sp)
    addi    $sp,            $sp,    4
    jr      $ra

loop3:
    bge     $a3,            $a2,    back

    addi    $sp,            $sp,    -4
    sw      $ra,            0($sp)
# offset em relação ao índece i
    sll     $t2,            $a3,    2
# offset em relação ao índice p
    sll     $t3,            $a0,    2
# somando os offset
    addu    $t4,            $t2,    $s0     # lembrando que $s0 armazena o emdereço da memória alocada  # $t4 armazena o endereço i do vetor
    addu    $t5,            $t3,    $s0     # lembrando que $s0 armazena o emdereço da memória alocada  # $t5 armazena o endereço de p do vetor

#obtem os valores dessas posições de memória
    lw      $s1,            0($t4)          # $s1 armazena o conteúdo de v[i]
    lw      $s2,            0($t5)          # $s2 armazena o conteúdo de v[p]
    jal     if
    addi    $a3,            $a3,    1
    j       loop3

back:
    lw      $ra,            0($sp)
    addi    $sp,            $sp,    4
    jr      $ra

if:
    bge     $s1,            $s2,    else
    move    $t6,            $s1
    sw      $t6,            0($t5)
    sw      $s2,            0($t4)
    jr      $ra
