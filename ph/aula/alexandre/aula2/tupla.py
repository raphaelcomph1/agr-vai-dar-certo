#tupla sao arrays imutaveis 

t = 'a','b','c','d','e'
print(t)


#tupla de um unico elemento 
t1 = 'a',
print()
print(t1)
print(type(t1))

# cada caracter vira posicao na tupla 

t2 = tuple('abdadw')
print()
print(t2)


# operator do conchetes 

print(t2[1:3])


t_new = ('A',) + t[1:]
print()
print(t_new)

