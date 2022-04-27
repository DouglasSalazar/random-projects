#! /usr/bin/python/

class loja:
	def __init__(self):
		self.tam = 0
		self.lpm = 3
		self.latas = 18
		self.preco = 80
		self.total = 0
	
	def ler(self):
		self.tam = input("\nInforme a area a ser pintada\n" )
	
	def calc(self):
		self.total = int(self.tam) / int(self.lpm)
		self.total = self.total + 1
		self.total = self.total / self.latas
		self.total = self.total + 1
		self.total = self.total * self.preco

	def imprimi (self):
		print "Sera necessario \n Preco: ",self.total," Latas:",self.total/self.preco,


if '__main__' == __name__:
	lj=loja()
	lj.ler()
	lj.calc()
	lj.imprimi()

