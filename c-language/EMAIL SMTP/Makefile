all:
	gcc -o Email Email.c -Wall -pedantic -Wextra -lssl -lcrypto `pkg-config --cflags --libs gtk+-2.0` -g
clean:
	rm *~
	rm Email
