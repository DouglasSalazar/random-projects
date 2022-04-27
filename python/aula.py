#!/usr/bin/python

class objeto:

	def __init__(self):
		self.abre = open("texto.txt", "r")
		self.leia = []
		

	def ler_arquivo(self):

		'''print "===== 1 LEITURA ======= \n"
		self.leia = self.abre.read()
		print self.leia, "\n"'''

		'''print "===== 2 LEITURA ======= \n"
		self.leia = self.abre.readline()
		print self.leia, "\n"'''

		print "===== 3 LEITURA ======= \n"
		self.leia = self.abre.readlines()
		for i in self.leia:
			print "\n" , i, "\n"

		#print self.leia, "\n"

		self.abre.close()
'''inicio'''

if __name__ == '__main__':

	obj = objeto()
	obj.ler_arquivo()