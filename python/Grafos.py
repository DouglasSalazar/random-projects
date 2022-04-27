import networkx as nx
import matplotlib.pyplot as plt
import numpy as n
import sys

def separar(str, at):
        returns = []
        temp = ''
        for char in str:
                if char in at:
                		if temp != '':
                			returns.append(temp)
                		temp = ''
                else:
                        temp += char
        if temp != '':
                returns.append(temp)
        return returns

class grafos:
	def __init__(self):
		self.g=nx.Graph()

	def Criacao(self):
		vect=[]
		print 'Formato de arquivo Valido'
		print '1 Linha= {a,b,c,d}'
		print '2 Linha= [(a,b) (a,c) (c,d)]\n\n'
		nome= raw_input('Informe o nome do arquivo.txt\n')
		arquivo=open(nome,'r')
		texto=arquivo.readline()
		
		texto=separar(texto,['{','}','\n',','])
		self.g.add_nodes_from(texto)

		texto=arquivo.readline()
		texto=separar(texto,['',' ','[',']','(',')','\n'])
		for vect in texto:
			a,b=vect.split(',')
			self.g.add_edge(a,b)

	def Criacao2(self):
		vect=[]
		print 'Formato de arquivo Valido'
		print '1 Linha= {a,b,c,d}'
		print '2 Linha= [(a,b) (a,c) (c,d)]'
		print '3 Linha= [1 2 3]\n\n'
		nome= raw_input('Informe o nome do arquivo.txt\n')
		arquivo=open(nome,'r')
		texto=arquivo.readline()
		
		texto=separar(texto,['{','}','\n',','])
		self.g.add_nodes_from(texto)

		texto=arquivo.readline()
		texto=separar(texto,['',' ','[',']','(',')','\n'])

		for vect in texto:
			a,b=vect.split(',')
			self.g.add_edge(a,b)

		texto=arquivo.readline()
		texto=separar(texto,['',' ','[',']','\n'])		
		for v1,v2 in self.g.edges():
			if ('weight' not in self.g[v1][v2]):
				self.g[v1][v2]['weight'] = int(texto.pop(0))

	def Desenha(self):
		pos=nx.spring_layout(self.g)
		nx.draw_networkx_nodes(self.g,pos,node_size=700)
		nx.draw_networkx_labels(self.g,pos,font_size=20,font_family='sans-serif')
		nx.draw_networkx_edges(self.g,pos,width=2)
		plt.show()

def busca_largura(g,s,f):
	cor={}
	dist={}
	pre={}
	prec={}
	fila=[s]

	for V in g.nodes():
		dist[V]=float('Inf')
		cor[V]='Branco'
		prec[V]='NULO'

	cor[s]='Azul'
	dist[s]=0
	prec[s]='NULO'

	while fila:
		u=fila.pop(0)
		for V in g.neighbors(u):
			if cor[V]=='Branco':
				cor[V]='Azul'
				dist[V]=dist[u]+1
				prec[V]=u;
				fila.append(V)
				if V == f:
					print cor
					print dist
					print prec
					print fila
					return

		cor[u]='Vermelho'

def Busca_prof(visitado,prenum,V,g):
	visitado[V]='V'
	global pnum
	pnum=pnum+1
	prenum[V]=pnum

	for w in g[V]:
		if visitado[w]=='F':
			Busca_prof(visitado,prenum,w,g)

def busca(g):
	visitado={}
	prenum={}
	global pnum
	pnum=0

	for V in g.nodes():
		visitado[V]='F'

	for V in g.nodes():
		if visitado[V]=='F':
			Busca_prof(visitado,prenum,V,g);

	print prenum
	print visitado
	print pnum

def Busca_prof_lim(visitado,prenum,V,g,stop):
	visitado[V]='V'
	global pnum
	pnum=pnum+1
	prenum[V]=pnum

	for w in g[V]:
		if pnum<stop:
			if visitado[w]=='F':
				Busca_prof_lim(visitado,prenum,w,g)

def busca_lim(g,stop):
	visitado={}
	prenum={}
	global pnum
	pnum=0

	for V in g.nodes():
		visitado[V]='F'

	for V in g.nodes():
		if pnum<stop:
			if visitado[V]=='F':
				Busca_prof_lim(visitado,prenum,V,g);

	print prenum
	print visitado
	print pnum

def Dijkstra(g, s):
    Lambda = {}            
    pred = {}              
    Q = g.nodes()          

    for v in g.nodes():
        Lambda[v] = n.inf

    for v1,v2 in g.edges():
        if ('weight' not in g[v1][v2]):
            g[v1][v2]['weight'] = 1

    Lambda[s] = 0
    pred[s] = None

    while Q:

        menor = n.inf
        u     = Q[0]
        if sys.version_info[0] < 3:
            for k,v in Lambda.iteritems():
                if (v < menor) and (k in Q):
                    menor = v
                    u = k
        else:
            for k,v in Lambda.items():
                if (v < menor) and (k in Q):
                    menor = v
                    u = k

        u_index = Q.index(u)
        del Q[u_index]

        for v in g[u]:
            if (v in Q) and (Lambda[v] > Lambda[u] + g[u][v]['weight']):
                Lambda[v] = Lambda[u] + g[u][v]['weight']
                pred[v] = u

    print Lambda
    print pred

if '__main__'==__name__:
	G=grafos()
	V=1
	while V:
		menu=raw_input("Algortimos de Busca\n1>Largura\n2>Profundidade\n3>Custo Uniforme\n4>Profundidade Limitada\n5>Desenhar Grafo\n6>Sair\n")
		if(menu=='1'):
			G.Criacao()
			s=raw_input("Informe estado inicial\n")
			f=raw_input("Informe fim da Busca\n")
			busca_largura(G.g,s,f)
		if(menu=='2'):
			G.Criacao()
			busca(G.g)
		if(menu=='3'):
			G.Criacao2()
			s=raw_input("Informe estado inicial\n")
			Dijkstra(G.g,s)
		if(menu=='4'):
			G.Criacao2()
			stop=input("Informe o Limite\n")
			busca_lim(G.g,stop)
		if(menu=='5'):
			G.Desenha();
		if(menu=='6'):
			V=0
