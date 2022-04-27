

num = int(raw_input("numero:"))
invertido = 0
while num>0:
    invertido = invertido * 10 + num % 10
    num = num / 10
print invertido
