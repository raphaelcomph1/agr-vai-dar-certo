msgs = input('a: ')
dicionario = {}


def contador(s):
    for c in s:
        if c not in dicionario:
            dicionario[c] = 1
        else:
            dicionario[c] += 1
    return dicionario

print(contador(msgs))

#penis