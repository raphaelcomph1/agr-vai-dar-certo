n = 0
while n<0:
    n= int(input('digite o num de posicoes do vetor: '))
    vetor = []


print('a')
for i in range(n):
    crt = input(f'posicao{i}:')
    vetor.append(crt)

#exibir do vetor original

print('\n Vetor original:', vetor)

#Inversao natural do vetor

for i in range(n//2):
    #troca os elementos das extremidades 
    temp = vetor[i]
    vetor[i] = vetor[n -i -1]
    vetor[n -1 -i] = temp

print(vetor)


