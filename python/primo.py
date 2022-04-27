

def primo(n):
	i=1
	aux=0
	while i<=n:
		if (n%i) == 0:
			aux=aux+1
		i=i+1

	if aux<=2:
		print "Numero e Primo"
	else: 
		print "Numero nao e Primo"

n=input ("INforme o numero a ser verificado ")

primo(n)
