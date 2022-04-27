def calc_inss(sal_bruto):
	return sal_bruto*0.08

def calc_imposto(sal_bruto):
	return sal_bruto*0.11

def calc_sindicato(sal_bruto):
	return sal_bruto*0.05

menu=1
sal_bruto=0
sal_liquido=0
hora=0
while(menu!=2):
	hora=input("Entre com as horas trabalhadas no mes: ")
	v_hora=input("Entre com o valor das horas trabalhadas: ")
	sal_bruto=hora*v_hora
	inss=calc_inss(sal_bruto)
	imposto=calc_imposto(sal_bruto)
	sindicato=calc_sindicato(sal_bruto)
	sal_liquido=sal_bruto-inss-imposto-sindicato

	print "+ Salario Bruto: R$",sal_bruto
	print "- INSS (8%): R$",inss
	print "- IR (11%): R$",imposto
	print "- Sindicato (5%): R$",sindicato
	print "= Salario Liquido: R$",sal_liquido
	menu=input("Deseja continuar 1-Sim 2-Nao ")
