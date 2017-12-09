#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

unsigned short int entrada(char *b, unsigned short int *x, unsigned short int *y){
	unsigned short int ok,let=0,num=0, i=0;
	unsigned short int po=0;
	unsigned short int lado=0,cima;
	
	while(b[i]!='\0'){
		ok=b[i];
		if((ok<'0' || (ok>'9' && ok<'A') || (ok>'L' && ok<'a') || ok>'l') && (ok!=' ')){ //trechos nao permitidos da tabela ascii//
			printf("entranda invalida \n");
			return 0;
		}
		if(ok>='0' && ok<='9'){
			num++;
		}
		i++;
	}
	i=0;
	while(b[i]!='\0'){
		ok=b[i];
		if(ok>='0' && ok<='9'){
			lado=ok-'0';//conversao para int//
			num=num-1;
		}
		if(ok>='A' && ok<='L'){
			cima=(ok-'A');
			let++;
		}
		if(ok>='a' && ok<='l'){
			cima=(ok-'a');
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
	(*x)=lado;
	(*y)=(cima);
	printf("entendido capitao \n");
	return 1;
}
