# determine e mostre todos os numeors primos de 2 a 2000
n = int(input('digite um valor:'))
primo = True 



# for n in range(0, 2000):
#     for j in range(2, n):
#         if n % j > 0:
#             continue
# print(n)

for n in range(2, 2000):
    for divisor in range(2, n):
        if n % divisor == 0:
            primo = False
            break
    if primo:
        print(n)






