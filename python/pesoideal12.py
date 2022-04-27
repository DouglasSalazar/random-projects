def pesoidealhomem(altura):
	return (72.7*altura)-58
def pesoidealmulher(altura):
	return (62.1*altura)-44.7
menu=1
aux=0
while(menu!=2):
	menu=input("1>Peso ideal mulher 2>Peso ideal Homem: ")
	altura=input("Entre com a altura: ")
	peso=input("Entre com o peso: ")
	if(menu==2):	
		aux=pesoidealmulher(altura)
		print "Peso ideial: ",aux
		if(aux==peso):
			print "Voce esta no peso ideal"
		else:
			print "Voce nao esta no peso ideal"
	if(menu==1):
		aux=pesoidealhomem(altura)
		print "Peso ideial: ",aux
		if(aux==peso):
			print "Voce esta no peso ideal"
		else:
			print "Voce nao esta no peso ideal"
	menu=input("Deseja continuar 1-Sim 2-Nao ")
