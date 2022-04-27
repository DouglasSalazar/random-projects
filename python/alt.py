
def leia():
	v=[]
	i=0
	while i<=10:
		x=input("Informe o numero do aluno")
		y=input("Informe a altura do respectivo aluno")
		v=v+[x,y]
		i=i+1
	return v

def ver(v):
		
	maior = -999999
	ma=0
	menor = 9999999	
	me=0
	i=0	
	while i<10:
		if (menor > v[1][i]):
			menor=v[1][i]
			me=v[0][i]
		if (maior < v[1][i]):
			maior = v[1][i]
			ma=v[0][i]
		i=i+1
	print "A maior idade e",maior,"do aluno",ma
	print "A menor idade e",menor,"do aluno",me

v=leia()
ver(v)
