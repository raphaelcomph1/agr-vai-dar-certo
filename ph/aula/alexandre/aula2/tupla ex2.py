dominios = 'pedroalvarezcabral@fiap.com','qrfusgiondf@fiap.com','sidsobfdb@fiap.com','sfsdsdfsg@alura.com','ultimo@gamil.com'
dominiosNoDicionario = {}
print(f'primeiro{dominios[0]}\n ultimo{dominios[-1]}')

dominiosAtt = dominios[-1], dominios[0]
print(dominiosAtt)


def contador(s):
    for qtd in s:
        if qtd in dominiosAtt:
            dominiosNoDicionario[qtd] = 1
        else:
            dominiosNoDicionario[qtd] +=1
print(dominiosNoDicionario)