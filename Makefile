all: main
main.o: main.c funcoes.h
	gcc -g -c main.c
mapa.o: mapa.c funcoes.h
	gcc -g -c mapa.c
barcos.o: barcos.c funcoes.h
	gcc -g -c barcos.c
main: main.o mapa.o barcos.o
	gcc main.o mapa.o barcos.o -o main
clean:
	rm -f main
	rm -f *.o
