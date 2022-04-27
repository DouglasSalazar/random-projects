#!/usr/bin/python

class BV:
	def __init__(self):
		self.Nome='0'
		self.Fome='0'
		self.Saude='0'
		self.idade=0
	def AltNome(self):
		self.Nome=raw_input("Novo Nome: ")
	def AltFome(self):
		self.Fome=raw_input("Nova Fome: ")
	def AltSaude(self):
		self.Saude=raw_input("Nova Saude: ")
	def AltIdade(self):
		self.idade=raw_input("Nova idade: ")
	def returnNome(self):
		print self.Nome
	def returnFome(self):
		print self.Fome
	def returnSaude(self):
		print self.Saude
	def returnIdade(self):
		print self.idade
	
if '__main__'==__name__:
	Bichinho=BV()
	
	
		
	
	

