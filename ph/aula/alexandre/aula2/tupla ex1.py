a = 5
b = 10
print(f'a:{a}, b:{b}')
print()

a,b = b,a
print(a, b)

# separacao de ususario e dominio 

addr = 'rm123124235@fiap.com'
print()
print(addr)
unname, domain = addr.split('@')

print()
print(f'{unname}\n{domain}')