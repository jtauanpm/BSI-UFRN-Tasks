#(QUESTÃO 206) | lim f = (3-((5+x)**0.5))/(1-((5-x)**0.5))
#                   x->4

print("\n\n>>>>>>>>>>>> Usando vetores <<<<<<<<<<<<\n")

limitEsq = [3.98, 3.99, 3.999, 3.9999, 3.9999999]
print("\nLimites com X pela esquerda: \n")
for x in limitEsq:
    f = (3-((5+x)**0.5))/(1-((5-x)**0.5))
    print(f)

limitDir = [4.1, 4.01, 4.001, 4.0001, 4.0000001]
print("\nLimites com X pela direita: \n")
for x in limitDir:
    f = (3-((5+x)**0.5))/(1-((5-x)**0.5))
    print(f)


print("\n\n>>>>>>>>>>>> Usando biblioteca simbólica <<<<<<<<<<<<\n")

from sympy import symbols
from sympy import limit
x = symbols('x')
f = (3-((5+x)**0.5))/(1-((5-x)**0.5))
limite = limit(f, x, 4)
print("O limite da função é: %f\n" % limite)

print("\n\n>>>>>>>>>>>> Utilizando gráfico <<<<<<<<<<<<\n")
print("Pressione ENTER para gerar o gráfico.")
aux = input()


from sympy.plotting import plot
graph = plot((3-((5+x)**0.5))/(1-((5-x)**0.5)))