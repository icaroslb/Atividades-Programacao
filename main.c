#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	mapa *m;
	inicializar_mapa(&m);
	
	mostrar_mapa(m);
	return EXIT_SUCCESS;
}
