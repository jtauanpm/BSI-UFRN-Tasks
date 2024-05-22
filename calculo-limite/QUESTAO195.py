# (QUESTÃO 195) | lim f = (x**3 - 3*x + 2)/(x**4 - 4*x + 3) 
#                   x->1

print("\n\n>>>>>>>>>>>> Usando vetores <<<<<<<<<<<<\n")

limitEsq = [0.98, 0.99, 0.999, 0.9999, 0.99999]
print("\nLimites com X pela esquerda: \n")
for x in limitEsq:
    f = (x**3 - 3*x + 2)/(x**4 - 4*x + 3)
    print(f)

limitDir = [1.1, 1.01, 1.001, 1.00001, 1.000001]
print("\nLimites com X pela direita: \n")
for x in limitDir:
    f = (x**3 - 3*x + 2)/(x**4 - 4*x + 3)
    print(f)


print("\n\n>>>>>>>>>>>> Usando biblioteca simbólica <<<<<<<<<<<<\n")

from sympy import symbols
from sympy import limit
x = symbols('x')
f = (x**3 - 3*x + 2)/(x**4 - 4*x + 3)
limite = limit(f, x, 1)
print("O limite da função é: %f\n" % limite)


print("\n\n>>>>>>>>>>>> Utilizando gráfico <<<<<<<<<<<<\n")
print("Pressione ENTER para gerar o gráfico.")
aux = input()

from sympy.plotting import plot
graph = plot((x**3 - 3*x + 2)/(x**4 - 4*x + 3))
