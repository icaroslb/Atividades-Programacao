#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//função que inicializa um nó
void iniciNo(mapa **no, unsigned short int x, unsigned short int y){
	*no=(mapa*)malloc(sizeof(mapa));
	(*no)->x=x;
	(*no)->y=y;
	(*no)->valorH=' ';
	(*no)->valorC=' ';
	(*no)->baixo=NULL;
	(*no)->esq=NULL;
	(*no)->dir=NULL;
	(*no)->barcoH=NULL;
	(*no)->barcoC=NULL;
}

//função que iniciliza o mapa
void inicializar_mapa(mapa **m){
	mapa *ini, *novo, *aux, *cima=NULL;
	unsigned short int x, y;
	
	for(x=0; x<TAMMAPAX; x++){
		y=0;
		iniciNo(&ini, x, y);
		if(x==0){*m=ini;}
		if(cima!=NULL){
			ini->cima=cima;
			cima->baixo=ini;
			cima=cima->dir;
		}
		novo=ini;
		for(y=1; y<TAMMAPAY; y++){
			aux=novo;
			iniciNo(&novo, x, y);
			aux->dir=novo;
			novo->esq=aux;
			if(cima!=NULL){
				novo->cima=cima;
				cima->baixo=novo;
				cima=cima->dir;
			}
		}
		novo->dir=ini;
		ini->esq=novo;
		cima=ini;
	}
	inicializar_barcos(*m);
}

//função que passa uma posição como parâmetro e ela retorna o endereço da posição
mapa* caminhar(mapa *m, unsigned short int x, unsigned short int y){
	//caminha para a linha requerida
	if((m->x)<x){
		while((m->x)<x){
			m=m->baixo;
		}
	}else{
		while((m->x)>x){
			m=m->cima;
		}
	}
	//caminha para a coluna requerida
	if((m->y)<y){
		while((m->y)<y){
			m=m->dir;
		}
	}else{
		while((m->y)>y){
			m=m->esq;
		}
	}
	return m;
}

//função que imprime na tela os mapas
void mostrar_mapa(mapa *m){
	unsigned short int x, y;
	mapa *humano=m, *computador=m;
		
	printf("      Humano\t\t\t    Computador\n");
	printf("   ABCDEFGHIJKL\t\t\t   ABCDEFGHIJKL\n");
	printf("  +------------+\t\t  +------------+\n");

	for(x=0; x<TAMMAPAX; x++){
		printf("%2d|", x);
		for(y=0; y<TAMMAPAY; y++){
			printf("%c", humano->valorH);
			humano=humano->dir;
		}
		humano=humano->baixo;
		printf("|\t\t");
		printf("%2d|", x);
		for(y=0; y<TAMMAPAY; y++){
			printf("%c", computador->valorC);
			computador=computador->dir;
		}
		computador=computador->baixo;
		printf("|\n");
	}
	printf("  +------------+\t\t  +------------+\n");
}
