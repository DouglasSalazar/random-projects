#!/usr/bin/python

class pessoa:
	def __init__(self):
		self.Nome='0'
		self.idade=0
		self.peso=0
		self.altura=0
	def Infor(self):
		self.nome=raw_input("Nome: ")
		self.idade=input("Idade: ")
		self.peso=input("Peso: ")
		self.altura=input("Altura: ")	
	def Envelhecer(self):
		self.idade=input("Nova idade: ")
	def Engordar(self):
		self.peso=input("Novo peso: ")
	def Emagrecer(self):
		self.peso=input("Novo peso: ")
	def crescer(self):
		self.altura=input("Novo peso: ")
	
if '__main__'==__name__:
	pessoa1=pessoa()
	pessoa1.Infor()

	
		
