import random as r

#solicitar o numero de linhas e counas da matriz 
#coloca como input dps

qtd_linhas = 2
qtd_colunas = 5


#criacao das matriz 
a = []
b = []
c = []

# preencher matriz a 
for i in range(qtd_linhas):
    linha = []
    linha2 = []
    for j in range(qtd_colunas):
        valorA = r.randint(-10,10)
        valorb = r.randint(-10,20)
        linha.append(valorA)
        linha2.append(valorb)
    a.append(linha)
    b.append(linha2)

for linha in a:
    print(linha)
print()
for linha2 in b:
    print(linha2)

#soma 
print()
for i in range(qtd_linhas):
    soma = []
    for j in range(qtd_colunas):
        valor_soma = a[i][j] + b[i][j]
        soma.append(valor_soma)
    c.append(soma)
for soma in c:
    print(soma) 