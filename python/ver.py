#!/usr/bin/python/

def paroimpar(n1,n2):
	if n1%2 == 0:
		print "Numero ",n1,"e par"
	else:
		print "Numero ",n1,"e impar"

	if n2%2 == 0:
		print "Numero ",n2,"e par"
	else:
		print "Numero ",n2,"e impar"

def positivo_negativo(n1,n2):
	if n1 < 0:
		print "Numero",n1,"e negativo"
	else:
		print "Numero",n1,"e positivo"


	if n2 < 0:
		print "Numero",n2,"e negativo"
	else:
		print "Numero",n2,"e positivo"

i=0
while i<>3:
	i=input("Escolha a opcao \n\n1-Numeros pares e inpares\n2-Numeros negativos e positivos\n3-sair")
	n1=input("INforme 1 numero")
	n2=input("INforme 2 numero")	
	if i==1:
		paroimpar(n1,n2)
	elif i==2: 
		positivo_negativo
