#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>

int main(){
	/*mapa *m, *computador;
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
	}*/
	
	
	unsigned short int certo, x, y;
	char a[4];
	
	certo=entrada(&x, &y);
	printf("%d %d %d", certo, x, y);
	return EXIT_SUCCESS;
}
