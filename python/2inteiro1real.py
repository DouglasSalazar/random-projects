#!/usr/bin/env/python

def dobro(x,y):
	return (x*2)*(y/2)

def triplo(x,z):
	return (x*3)+z

def elevado(z):
	return z**3

menu=0
aux=0
while(menu!=2):

	x=int(input("Entre com o Primeiro numero inteiro: "))
	y=int(input("Entre com o Segundo numero inteiro: "))
	z=float(input("Entre com o Primeiro numero Real: "))
	
	aux=dobro(x,y)
	print "O produto do dobro do primeiro com metade do segundo e: ",aux
	aux=triplo(x,z)
	print "A soma do tripro do primeiro com o terceiro e: ",aux
	aux=elevado(z)
	print "O terceiro elevado ao cuboe: ",aux

	menu=input("Deseja continuar 1-Sim 2-Nao ")
