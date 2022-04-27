#!/usr/bin/python

from random import randrange

vetor = []

for i in range(6):
	vetor.append(0)



for i in range(100):

	num = randrange(1,7)

	if num == 1:
		vetor[0] = vetor[0] + 1
	if num == 2:
		vetor[1] = vetor[1] + 1
	if num == 3:
		vetor[2] = vetor[2] + 1
	if num == 4:
		vetor[3] = vetor[3] + 1
	if num == 5:
		vetor[4] = vetor[4] + 1	
	if num == 6:
		vetor[5] = vetor[5] + 1
for i in range(6):
	
	print 'Numeros ',i+1,' ',vetor[i] 
