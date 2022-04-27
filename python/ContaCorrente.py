#!/usr/bin/python

class ContaC:
	def __init__(self):
		self.NumeroConta=0
		self.Nome=' '
		self.saldo=0	
	def AltNome(self):
		self.Nome=input("Nova Nome: ")
	def deposito(self):
		deposito=input("Valor a ser depositado: ")
		self.saldo=self.saldo+deposito
		print self.saldo
	def Saque(self):
		saque=input("Valor a ser sacado: ")
		self.saldo=self.saldo-saque
		print self.saldo
	
if '__main__'==__name__:
	Conta=ContaC()
	Conta.deposito()
	Conta.Saque()

	
		
