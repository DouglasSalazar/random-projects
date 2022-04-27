#!/usr/bin/python

class retangulo:
	def __init__(self):
		self.LadoA=0
		self.LadoB=0
	def mudavalor(self):
		self.LadoA=input("Novo valor lado A: ")
		self.LadoB=input("Novo valor lado B: ")
	def retornarlados(self):
		print "Lado A:\n",self.LadoA,"Lado B:\n",self.LadoB
	def calc_area(self):
		return self.LadoA*self.LadoB
	def calc_perimetro(self):
		return (self.LadoA*2)+(self.LadoB*2)
	
if '__main__'==__name__:
	local=retangulo()
	ladrilho=retangulo()
	print "Informe os lados da area"	
	local.mudavalor()
	print "Informe os lados do ladrilho"
	ladrilho.mudavalor()
	arealocal=local.calc_area()
	arealadrilho=ladrilho.calc_area()
	total=arealocal/arealadrilho
	print "Sao necessarios: ",total,"Ladrilhos"
	
		
	
	

