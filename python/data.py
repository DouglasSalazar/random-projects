#!/usr/bin/python/

class data:
		
	def __init__(self):
		self.data = ''
		self.vetor=[]
		self.dia=0
		self.mes=0
		self.ano=0

	def leia(self):
		self.data=raw_input("Informe a data no formato dd/mm/aaaa" )
	

	def valida(self):
		
		for x in self.data.split('/'):	
			self.vetor.append(x)	
		self.dia=int(self.vetor[0])
		self.mes=int(self.vetor[1])
		self.ano=int(self.vetor[2])
		if self.dia > 1 and self.dia < 31:
			if self.mes > 1 and self.mes < 12:
				if self.ano >1:
					print "Data Valida"
				else:
					print "Data Invalida"
			else:
				print "Data Invalida"
		else:
			print "Data Invalida"

if '__main__'==__name__:
	dt=data()
	dt.leia()
	dt.valida()
