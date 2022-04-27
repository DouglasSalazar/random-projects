#!usr/bin/env/python

def soma(x,y):
	return x+y

def subt(x,y):
	return x-y

def mult(x,y):
	return x*y

def div(x,y):
	return x/y
menu=0
aux=0
while(menu!=1):

	print "CALCULADORA"
	print"Informe uma das opcoes"
	print "Entre com o operador "		
	menu=raw_input()
	x=input("Entre com o primeiro Valor ")
	y=input("Entre com o primeiro Valor ")

	if(menu=="+"):	
		aux=soma(x,y)
		print"A soma de",x,"+",y,"=",aux
	else:
		if(menu=="-"):
			aux=subt(x,y)
			print"A Subtracao de",x,"-",y,"=",aux	
		else: 
			if(menu=="*"):
				aux=mult(x,y)	
				print"A Multiplicacao de",x,"*",y,"=",aux						
			else: 
				if(menu=="/"):
					aux=div(x,y)
					print"A Divisao de",x,"/",y,"=",aux
				else:
					print "Opcao Invalida"
	
	menu=input("Deseja continuar 0-Sim 1-Nao ")
