
def leia():
	v=[]
	n=input ("Informe o numero de idades a serem informados")
	i=0
	while (i<=n):
		aux=input("Informe a idade ")
		v.append(aux)
		i=i+1
	return v

def calc(v):
	aux=0
	j=0
	for i in v:
		aux=aux+i
		j=j+1

	aux=aux/j
	
	if(aux >0 and aux <25):
		print "Turma jovem"
	if(aux >=25 and aux <=60):
		print "Turma Adulta"
	if(aux >60):
		print "Turma idosa"


v=leia()
calc(v)
