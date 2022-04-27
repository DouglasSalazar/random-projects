all:
	gcc -Wall -Wextra -pedantic -c bin/relacao.c -o lib/relacao.o
	gcc -Wall -Wextra -pedantic -c bin/grupo.c -o lib/grupo.o
	gcc -Wall -Wextra -pedantic -c bin/contato.c -o lib/contato.o
	gcc -Wall -Wextra -pedantic -c bin/arquivo.c -o lib/arquivo.o 
	gcc -o Contato Contato.c -Wall -Wextra -pedantic lib/arquivo.o lib/contato.o lib/grupo.o lib/relacao.o

clear:
	rm *~
	rm contato
	rm relacao
	rm grupo	
