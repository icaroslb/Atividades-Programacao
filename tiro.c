#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void jangada_destruida(sub *submarinos, unsigned short int humcomp){
	
	if(humcomp==HUMANO){
		if(((submarinos->subH1)->barcoH)->dano==0){
			((submarinos->subH1)->barcoH)->dano=1;
			(submarinos->subH1)->valorH='@';
			printf("acertamos o nosso x9!\n");
		}else if(((submarinos->subH2)->barcoH)->dano==0){
			((submarinos->subH2)->barcoH)->dano=1;
			(submarinos->subH2)->valorH='@';
			printf("acertamos o nosso x9!\n");
		}
	}else{
		if(((submarinos->subC1)->barcoC)->dano==0){
			((submarinos->subC1)->barcoC)->dano=1;
			(submarinos->subC1)->valorC='*';
			printf("acertaram o x9 deles huehuehue!\n");
		}else if(((submarinos->subC2)->barcoC)->dano==0){
			((submarinos->subC2)->barcoC)->dano=1;
			(submarinos->subC2)->valorC='*';
			printf("acertaram o x9 deles huehuehue!\n");
		}
	}
}

unsigned short int destruido(mapa *m, unsigned short int humcomp){
	mapa *aux=m;
	unsigned short int todo;
	
	if(humcomp==HUMANO){
		if((m->barcoC)->parte=='@' || (m->barcoC)->parte=='&'){
			m->valorC=(m->barcoC)->parte;
			(m->barcoC)->dano=1;
		}else{
			if((aux->barcoC)->pos==HORIZONTAL){
				while((aux->barcoC)->parte!='<'){
					aux=aux->esq;
				}
				while((aux->valorC=='*') && (aux->barcoC)->parte!='>'){
					(aux->barcoC)->dano=1;
					aux->valorC=(aux->barcoC)->parte;
					aux=aux->dir;
					todo=1;
				}
				if(aux->valorC!='*'){
					while((aux->barcoC)->parte!='<'){
						aux=aux->esq;
						(aux->barcoC)->dano=0;
						aux->valorC='*';
						todo=0;
					}
				}
			}else{
				while((aux->barcoC)->parte!='^'){
					aux=aux->cima;
				}
				while((aux->valorC=='*') && (aux->barcoC)->parte!='v'){
					(aux->barcoC)->dano=1;
					aux->valorC=(aux->barcoC)->parte;
					aux=aux->baixo;
					todo=1;
				}
				if(aux->valorC!='*'){
					while((aux->barcoC)->parte!='^'){
						aux=aux->cima;
						(aux->barcoC)->dano=0;
						aux->valorC='*';
						todo=0;
					}
				}
			}
		}
	}else{
		if((m->barcoH)->parte=='@' || (m->barcoH)->parte=='&'){
			m->valorH='*';
			(m->barcoH)->dano=1;
		}else{
			if((aux->barcoH)->pos==HORIZONTAL){
				while((aux->barcoH)->parte!='<'){
					aux=aux->esq;
				}
				while((aux->valorH=='*') && (aux->barcoH)->parte!='>'){
					(aux->barcoH)->dano=1;
					aux=aux->dir;
					todo=1;
				}
				if(aux->valorH!='*'){
					while((aux->barcoH)->parte!='<'){
						aux=aux->esq;
						(aux->barcoH)->dano=0;
						todo=0;
					}
				}
			}else{
				while((aux->barcoH)->parte!='^'){
					aux=aux->cima;
				}
				while((aux->valorH=='*') && (aux->barcoH)->parte!='v'){
					(aux->barcoH)->dano=1;
					aux=aux->baixo;
					todo=1;
				}
				if(aux->valorH!='*'){
					while((aux->barcoH)->parte!='^'){
						aux=aux->cima;
						(aux->barcoH)->dano=0;
						todo=0;
					}
				}
			}
		}
	}
	return todo;
}

unsigned short int tiro(mapa *m, sub *submarinos, unsigned short int humcomp){
	mapa *aux=m;
	unsigned short int todo;
	
	if(humcomp==HUMANO){
		if(aux->valorC!=' '){
			printf("destruir oq ja foi atingido não pode atingir mais ;-;\n ");//parte ja sofreu dano
			return HUMANO; //para identificar um local q ja sofreu dano
		}
		if(aux->barcoC==NULL){
			aux->valorC='O';//essa parte show sera exibida no print do mapa
			return COMPUTADOR;//para identificar um acerto no mar
		}else{
			// INICIO
			todo=destruido(m, humcomp);
			if(todo==0){//ainda tem partes sem dano
				printf("tiramos uma parte da existencia daquela embarcaco\n");
				m->valorC='*';
			}else{
				printf("Kill exp +100\nvc destruiu aquele desnaturado\n"); 
				return HUMANO;//tipo de retorno q identifica acerto
			}
			if((aux->barcoC)->parte=='&'){
				jangada_destruida(submarinos, humcomp);
				return COMPUTADOR;
			}
		}
	}else{
		if(aux->valorH==' '){
			aux->valorH='O';
			return HUMANO;
		}
		aux->valorH='*';
		todo=destruido(m, humcomp);
		if((aux->barcoH)->parte=='&'){
			jangada_destruida(submarinos, humcomp);
			return HUMANO;
		}
		aux->valorH='*';
			printf("aquele maldito nos acertou!\n");
		return COMPUTADOR;
	}
}//fecha a funcao
