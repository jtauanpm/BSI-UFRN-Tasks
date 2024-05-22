#(QUESTÃO 207) | lim f = (((1+x)**0.5)-((1-x)**0.5))/x
#                   x->0

print("\n\n>>>>>>>>>>>> Usando vetores <<<<<<<<<<<<\n")

limitEsq = [-0.1, -0.001, 0.0001, -0.00001, -0.00000001]
print("\nLimites com X pela esquerda: \n")
for x in limitEsq:
    f = (((1+x)**0.5)-((1-x)**0.5))/x
    print(f)

limitDir = [0.1, 0.01, 0.001, 0.0001, 0.0000001]
print("\nLimites com X pela direita: \n")
for x in limitDir:
    f = (((1+x)**0.5)-((1-x)**0.5))/x
    print(f)


print("\n\n>>>>>>>>>>>> Usando biblioteca simbólica <<<<<<<<<<<<\n")

from sympy import symbols
from sympy import limit
x = symbols('x')
f = (((1+x)**0.5)-((1-x)**0.5))/x
limite = limit(f, x, 0)
print("O limite da função é: %f\n" % limite)

print("\n\n>>>>>>>>>>>> Utilizando gráfico <<<<<<<<<<<<\n")
print("Pressione ENTER para gerar o gráfico.")
aux = input()


from sympy.plotting import plot
graph = plot((((1+x)**0.5)-((1-x)**0.5))/x)