#!/usr/bin/python

class objeto:

	def abre_arq(self,nome):
		self.abre = open(nome, "r")
		self.leia = []
		

	def ler_arquivo_nome(self):
		nome=[]
		self.leia = self.abre.readlines()
		for i in self.leia:
			 nome=nome+[i]
		self.abre.close()
		return nome

	def ler_arquivo_hora(self):
		hora=[]
		self.leia = self.abre.readlines()
		for i in self.leia:
			 hora=hora+[i]
		self.abre.close()
		return hora

class cal:
	def __init__(self):
		self.sal_bruto=0
		self.inss=0
		self.saude=0
		self.liquido=0
		self.hora_extra=0
		self.dados=open("Salario.txt", "w")

	def calc_inss(self):
		return self.sal_bruto*(float(self.inss)/100)

	def calc_plano_saude(self):
		return self.sal_bruto*(float(self.saude)/100)


	def preenche(self,nome,hora):
		j=0
		i=0
	
		for i in nome:
			j=j+1
		i=0
		while(i<j):
			self.dados.write(nome[i])			
			v_hora=input("Entre com o valor das horas trabalhadas: ")
			a=hora[i]			
			self.sal_bruto=(float (a))*v_hora
			self.dados.write("\n+ Salario Bruto: R$")
			self.dados.write(str(self.sal_bruto))
			self.inss=input("Informe a taxa de inss em %: ")
			self.inss=self.calc_inss()
			self.dados.write("\n- INSS: R$")
			self.dados.write(str(self.inss))
			self.saude=input("Informe a taxa de Plano de saude em %: ")
			self.saude=self.calc_plano_saude()
			self.dados.write("\n- Plano de Saude: R$")
			self.dados.write(str(self.saude))
			self.hora_extra=input("Informe o numero de horas Extras:")
			self.hora_extra=self.hora_extra*v_hora
			self.dados.write("\n+ Hora extra: R$")
			self.dados.write(str(self.hora_extra))			
			self.liquido=(float(self.sal_bruto)-float(self.inss)-float(self.saude))+float(self.hora_extra)
			self.dados.write("\n+ Salario liquido: R$")
			self.dados.write(str(self.liquido))
			self.dados.write("\n\n-------------------------------------------------------------------\n\n")
			i=i+1
		self.dados.close()


if __name__ == '__main__':

	j=0
	obj = objeto()
	tb=cal()
	obj.abre_arq("nomes.txt")
	nome=obj.ler_arquivo_nome()
	obj.abre_arq("horatrabalho.txt")	
	hora=obj.ler_arquivo_hora()
	tb.preenche(nome,hora)
