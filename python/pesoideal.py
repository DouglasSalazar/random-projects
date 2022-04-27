def pesoideal(altura):
	return (72.7*altura)-58

menu=1
aux=0
while(menu!=2):

	altura=input("Entre com a altura: ")

	aux=pesoideal(altura)
	print "Peso ideial: ",aux

	menu=input("Deseja continuar 1-Sim 2-Nao ")
