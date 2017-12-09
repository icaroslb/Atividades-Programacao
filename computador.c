#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

unsigned short int decisao(mapa **m, sub *submarinos, unsigned short int computador){
	unsigned short int x, y, lado;
	mapa *aux=*m, *ant;
	
	srand(time(NULL));
	if((*m)->valorH!='*' || ((*m)->barcoH)->dano==1){
			printf("teste %d\n", aux->x);
			
		do{
			x=rand()%TAMMAPAX;
			y=rand()%TAMMAPAY;
			printf("%d %d\n", x, y);
			aux=caminhar(*m, x, y);
			printf("%d %d\n", aux->x, aux->y);
		}while(aux->valorH=='O' || aux->valorH=='*');
		computador=tiro(aux, submarinos, computador);
		if(aux->valorH=='*' && (aux->barcoH)->parte!='&'){
			printf("teste\n");
			*m=aux;
		}
	}else{
		do{		
			//Verifica se há posições disponíveis
			//Se a posição de cima não está disponível
			if((aux->cima)!=NULL && ((aux->cima)->valorH)=='*' || (aux->cima)!=NULL && ((aux->cima)->valorH)=='O'){
				//Se a posição de baixo não está disponível
				if((aux->baixo)!=NULL && ((aux->baixo)->valorH)=='*' || (aux->cima)!=NULL && ((aux->baixo)->valorH)=='O'){
					//Se a posição a direita não está disponível
					if((((aux->dir)->y)<(aux->y)) || ((aux->dir)->valorH)=='*' || ((aux->dir)->valorH)=='O'){
						//Se a posição a esquerda não está disponível
						if((((aux->esq)->y)>(aux->y)) || ((aux->esq)->valorH)=='*' || ((aux->esq)->valorH)=='O'){
							//Quando o barco está horizontal
							if((aux->barcoH)->pos==HORIZONTAL){
								while((aux->esq)->valorH=='*' && ((aux->barcoH)->parte)!='<'){
									aux=aux->esq;
								}
								while((aux->dir)->valorH=='*' && ((aux->barcoH)->parte)!='>'){
									aux=aux->dir;
								}
							//Quando o barco está na vertical
							}else{
								while(((aux->barcoH)->parte)!='^' && (aux->cima)->valorH=='*'){
									aux=aux->cima;
								}
								while(((aux->barcoH)->parte)!='v' && (aux->baixo)->valorH=='*'){
									aux=aux->baixo;
								}
							}
							*m=aux;
						}
					}
				}
			}
			lado=rand()%4;
			//Atira para cima
			if(lado==0){
				aux=aux->cima;
				if(aux!=NULL && aux->valorH!='O' && aux->valorH!='*'){
					ant=aux;
					computador=tiro(aux, submarinos, computador);
				}
			//Atira para o lado direito
			}else if(lado==1){
				aux=aux->dir;
				if((aux->y)>((*m)->y) && aux->valorH!='O' && aux->valorH!='*'){
					ant=aux;
					computador=tiro(aux, submarinos, computador);
				}
			//Atira para baixo
			}else if(lado==2){
				aux=aux->baixo;
				if(aux!=NULL && aux->valorH!='O' && aux->valorH!='*'){
					ant=aux;
					computador=tiro(aux, submarinos, computador);
				}
			//Atira para o lado esquerdo
			}else{
				aux=aux->esq;
				if((aux->y)<((*m)->y) && aux->valorH!='O' && aux->valorH!='*'){
					ant=aux;
					computador=tiro(aux, submarinos, computador);
				}
			}
		}while(aux==NULL || aux!=NULL && aux->valorH=='O' && aux!=ant || aux!=NULL && aux->valorH=='*' && aux!=ant);
		if(aux->valorH=='*'){
			*m=aux;
		}
	}
	return computador;
}
