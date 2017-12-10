#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

void limpar_teclado(){
	int tc;
	tc=getchar();
	while(tc!='\n' && tc!=EOF){tc=getchar();}
}

unsigned short int leitura(unsigned short int *x, unsigned short int *y){
	unsigned short int ent, coordx=0, coordy=0;
	
	*x=0;
	*y=0;
	ent=getchar();
	while(ent!='\0' && ent!='\n' && ent!=EOF){
		if(ent>='0' && ent<'9'){
			*x=((*x)*10)+(ent-'0');
			coordx+=1;
		}else if(ent>='A' && ent<='L'){
			*y=((*y)*10)+(ent-'A');
			coordy+=3;
		}else if(ent>='a' && ent<='l'){
			*y=((*y)*10)+(ent-'a');
			coordy+=3;
		}else if((ent>='M' && ent<='Z')||(ent>='m' %%ent<='z')){
			coordy+=6;
		}
		ent=getchar();
	}
	return (coordx+coordy);
}

void entrada(unsigned short int *x, unsigned short int *y){
	unsigned short int coord;
	
	do{
		printf("Insira as coordenadas: ");
		limpar_teclado();
		coord=leitura(x, y);
		if((*x)>12 || (*y)>12 || coord<3 || coord>5){
			printf("Entrada inválida!\n");
		}else{
			printf("Entendido capitão!\n");
		}
	}while((*x)>12 || (*y)>12 || coord<3 || coord>5);
}
