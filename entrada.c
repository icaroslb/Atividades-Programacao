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
			coordy+=1;
		}else if(ent>='a' && ent<='l'){
			*y=((*y)*10)+(ent-'a');
			coordy+=1;
		}
		ent=getchar();
	}
	return (coordx+coordy);
}

void entrada(unsigned short int *x, unsigned short int *y){
	/*unsigned short int ok,let=0,num=0, i=0;
	unsigned short int po=0;*/
	unsigned short int coord;
	
	do{
		printf("Insira as coordenadas: ");
		limpar_teclado();
		coord=leitura(x, y);
		if((*x)>12 || (*y)>12 || coord<2){
			printf("Entrada inválida!\n");
		}else{
			printf("Entendido capitão!\n");
		}
	}while(((*x)>12 && (*x)<0) || ((*y)>12 && (*y)<0));
	
	/*while(b[i]!='\0'){
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
	(*y)=(cima);*/
}
