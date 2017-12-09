#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

unsigned short int entrada(char *b, unsigned short int **x, unsigned short int **y){
	unsigned short int ok,let=0,num=0, i=0;
	unsigned short int po=0;
	unsigned short int lado=0,cima;
	
	while(b[i]!='\0'){
		ok=b[i];
		if(ok<48 || (ok>57 && ok<65) || (ok>77 && ok<97) || ok>109){ //trechos nao permitidos da tabela ascii//
			printf("entranda invalida \n");
			return 0;
		}
		if(ok>=48 && ok<=57){
			num++;
		}
		i++;
	}
	i=0;
	while(b[i]!='\0'){
		ok=b[i];
		if(ok>=48 && ok<=57){
			lado=ok-48;//conversao para int//
			num=num-1;
		}
		if(ok>=65 && ok<=77){
			cima=(ok-64);
			let++;
		}
		if(ok>=97 && ok<=109){
			cima=(ok-96);
			let++;
		}
		i++;
	}

	if(lado>12){
		printf("nao existe esse lado no tabuleiro \n");
		return 0;
	}
	if(let!=1){
		printf("nao tem essa coordenada \n");
		return 0;
	}
	cima=cima;
	lado=lado;
	(*x)=&lado;
	(*y)=&(cima);
	printf("entendido capitao \n");
	return 1;
}
