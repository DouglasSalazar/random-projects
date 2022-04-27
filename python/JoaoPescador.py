def multa(execesso):
	return execesso*4.0
menu=1
while(menu!=2):
	peso=input("Entre com o peso: ")
	if(peso<=50):	
		execesso=0
		multa=0
		print "Peixes estao no peso"
		print "Peso: ",peso
		print "Pese execedido: ",execesso
		print "Multa: R$",multa
	else:
		execesso=peso-50				
		multa=multa(execesso)	
		print "Peso: ",peso
		print "Pese execedido: ",execesso
		print "Multa: R$",multa	
	menu=input("Deseja continuar 1-Sim 2-Nao ")
