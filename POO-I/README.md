# :computer: Repositório destinado a resolução de exercícios da disciplina de Programação Orientada a Objetos - BSI-UFRN

### [Exercícios - Texto 02](https://sites.google.com/view/fabricio10/p%C3%A1gina-inicial/cursos/poo1/texto02)

### [Exercícios - Texto 03](https://sites.google.com/view/fabricio10/p%C3%A1gina-inicial/cursos/poo1/texto03)

### [Banco](https://sites.google.com/view/fabricio10/p%C3%A1gina-inicial/cursos/poo1/agrupando-objetos-3)

### Série de Lucas
Cada Série de Lucas tem dois números inteiros fixos, p e q, que servem para calcular os termos da série.
Os termos da série são calculados da seguinte maneira:
* o primeiro termo é sempre 0
* o segundo termo é sempre 1
* o terceiro termo é calculado com base nos dois termos anteriores e nos valores de p e q. Se Xn for o enésimo termo, ele deverá ser calculado assim: Xn = p*Xn-1 - q*Xn-2, onde Xn-1 é o termo anterior a Xn e Xn-2 é o termo anterior a Xn-1.

Exemplos:
  
Uma Série de Lucas com p=1 e q=-1 seria: 
0 1 1 2 3 5 8 13...
  
[a Série de Fibonacci é um caso particular da série de Lucas]
Uma série de Lucas com p=2 e q=1 seria:
0 1 2 3 4 5 6...

Uma série de Lucas com p=2 e q=-1 seria:
0 1 2 5 12 29...

Agora reflita sobre uma potencial classe, SerieDeLucas, para calcular termos de séries de Lucas nos mesmos moldes que a classe que estudamos, SerieDeFibonacci, calcula termos de uma série de Fibonacci (ver vídeo-aula no canal da disciplina). Um objeto dessa classe SerieDeLucas deve, essencialmente, calcular, termo a termo, os números da série através de chamadas de um mesmo método, cada chamada calculando o termo seguinte (como faz a classe SerieDeFibonacci). Sob hipótese nenhuma chamadas sucessivas a um método para calcular o termo seguinte, num mesmo objeto, devem retornar valores que não estejam de acordo com os valores p e q que foram atribuídos ao objeto quando de sua criação.

Escreva na classe um método para calcular o próximo termo da série e um método para saltar n termos na série. Escolha os parâmetros adequados para a classe.
  
### Escola
  Considere as classes...
public class Estado{
 private String nome;
 private Cidade[] cidades;
 //construtores, gets e sets...
}
  
public class Cidade{
 private String nome;
 private Escola[] escolas;
 //construtores, gets e sets...
}

public class Escola{
 private String nome;
 private ArrayList<Estudante> estudantes;
 //construtores, gets e sets...
}

public class Estudante{
 private Strig cpf;
 private int nivelLeitura;
 //construtores, gets e sets...
}

Escreva métodos gets, sets e construtores para as classes e escreva métodos, também, para:
* calcular nível médio de leitura de uma escola (média dos níveis de leitura dos estudantes)
* calcular nível médio de leitura de uma cidade (média dos níveis de leitura das escolas)
* calcular nível médio de leitura de um estado (média dos níveis de leitura das cidades)
* obter estudantes de uma escola que estejam acima de uma determinada média
* obter estudantes de uma escola que estejam acima da média da própria escola
  
### Rede de Mercadinhos
  
public class Produto{
   private String descricao;
   private double preco;
   //construtores, gets e sets
}

public class Item{
   private int quantidade;
   private Produto produto;
   //construtores, gets e sets
}
  
public class Venda{
   private String data;
   private Item[] itens;
   //construtores, gets e sets
}

public class Mercadinho{
   private Venda[] vendas;
   //construtores, gets e sets
}

* implemente uma rede de mercadinhos
* implemente método para retornar o total de todas as vendas de um mercadinho
* implemente método para retornar o total de vendas de toda uma rede de mercadinhos
* implemente método para retornar todas as vendas de um determinado mês
* implemente método para retornar o total de todas as vendas de um determinado mês
