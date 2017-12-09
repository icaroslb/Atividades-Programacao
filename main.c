#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	mapa *m, *computador;
	sub *submarinos=(sub*)malloc(sizeof(sub));
	unsigned short int humcomp=COMPUTADOR, i, teste;
	inicializar_mapa(&m, submarinos);
	computador=m;
	
	mostrar_mapa(m, &computador);
	for(i=0; i<5; i++){
		scanf("%hu", &teste);
		humcomp=decisao(&computador, submarinos, humcomp);
		mostrar_mapa(m, &computador);
		humcomp=COMPUTADOR;
	}
	return EXIT_SUCCESS;
}
