#! /usr/bin/python/



n=input("Informe o numero a ser invertido")
invertido =0
while n>0:
	invertido = invertido * 10 + n % 10
	n = n /10
print invertido
