#!/usr/bin/python

class Tv:
	def __init__(self):
		self.primeiroCanal=0
		self.ultimoCanal=0
		self.minimo=0
		self.maximo=0 	
	def AltDados(self):
		self.primeiroCanal=input("Informe Primeiro Canal: ")
		self.ultimoCanal=input("Informe Ultimo Canal: ")
		self.minimo=input("Informe Volume minimo: ")
		self.maximo=input("Informe Volume maximo: ")
	def Ver_canal(self,var):
		if var>=self.primeirocanal and var<=ultimocanal:
			print var
		else:
			print "Canal Inexiste"
	def Ver_volume(self,var):
		if var>=self.minimo and var<=maximo:
			print var
		else:
			print "Volume inexistente"	
if '__main__'==__name__:
	Tv=Tv()
	Tv.AltDados()

	
		
