import random as r


n = 0
while n <= 0:
    n = int(input('digite um num inteiro:'))

vetor = []

for i in range(n):
    num_ale = int(r.uniform(0, 100))
    vetor.append(num_ale)

print(vetor)