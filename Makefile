fila: fila.o main.o grafo.o lista.o
	gcc fila.o main.o grafo.o lista.o -o tp
grafo: grafo.o main.o fila.o lista.o
	gcc grafo.o main.o fila.o lista.o -o tp
lista: lista.o main.o grafo.o fila.o
	gcc lista.o main.o grafo.o fila.o -o tp
main.o: main.c fila.h grafo.h lista.h
	gcc -g -c main.c
fila.o: fila.h fila.c
	gcc -g -c fila.c
grafo.o: grafo.h grafo.c
	gcc -g -c grafo.c 
lista.o: lista.h lista.c
	gcc -g -c lista.c
clean:
	rm *.o *.gch
	rm grafo
	rm fila
	rm lista
