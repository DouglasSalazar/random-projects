#!/usr/bin/python

class Objeto:
	def __init__(self):
		self.Salario=0
		self.total_Dia=50
		self.Qntde_dia=0
	def Soma_Salario(self):
		self.Qntde_dia=input("Dias Trabalhados ")
		self.Salario=self.total_Dia*self.Qntde_dia
		print self.Salario

if '__main__'==__name__:
	obj=Objeto()
	obj.Soma_Salario()
