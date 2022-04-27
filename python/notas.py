#!/usr/bin/python/

def media(n1,n2,n3):
	media = (n1+n2+n3)/3
	if media >= 7:
		print "Aprovado"
	if media <= 7:
		print "Reprovado"
	if media == 10:
		print "Aprovado com Distincao"

n1=input("Informe a primeira nora")
n2=input("Informe a segunda nora")
n3=input("Informe a terceira nora")

media(n1,n2,n3)

