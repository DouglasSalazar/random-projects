#!/usr/bin/python

class quadrado:
	def __init__(self):
		self.Tamanho_Lado=0
	def Muda_valor(self):
		self.Tamanho_Lado=input("Informe novo valor lado: ")
	def retorna_lado(self):
		return self.Tamanho_Lado
	def calc_lado(self):
		print "Valor dos lados:",self.Tamanho_Lado
		area=self.Tamanho_Lado*self.Tamanho_Lado
		print "Area:",area

if "__main__"==__name__:
	obj=quadrado()
	obj.Muda_valor()
	obj.calc_lado()
	a=obj.retorna_lado()
	print a
