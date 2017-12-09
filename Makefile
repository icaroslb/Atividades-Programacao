all: main
main.o: main.c funcoes.h
	gcc -g -c main.c
mapa.o: mapa.c funcoes.h
	gcc -g -c mapa.c
barcos.o: barcos.c funcoes.h
	gcc -g -c barcos.c
tiro.o: tiro.c funcoes.h
	gcc -g -c tiro.c
entrada.o: entrada.c funcoes.h
	gcc -g -c entrada.c
computador.o: computador.c funcoes.h
	gcc -g -c computador.c
main: main.o mapa.o barcos.o tiro.o entrada.o computador.o
	gcc main.o mapa.o barcos.o tiro.o entrada.o computador.o -o main
clean:
	rm -f main
	rm -f *.o
