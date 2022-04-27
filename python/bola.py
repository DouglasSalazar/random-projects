#!/usr/bin/python

class Bola:
	def __init__(self):		
		self.Cor='Branco'
		self.circuferencia=2.0
		self.material='plastico'
	def trocacor(self):
		self.Cor=raw_input("Informe a cor a ser trocada ")
	def mostracor(self):
		print self.Cor

if'__main__'==__name__:
	obj=Bola()
	obj.trocacor()
	obj.mostracor()
