#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

unsigned short int tiro(mapa **h, sub *submarinos, unsigned short int humcomp){
	mapa *aux=*h;
	
if(humcomp==HUMANO){
		
	if(aux->barcoC==NULL){
		aux->valorC='O';//essa parte show sera exibida no print do mapa
		return COMPUTADOR;//para identificar um acerto no mar
	}


	/*if((aux->barcoC)->dano==1){
		printf("destruir oq ja foi destruido nao destroi mais ;-;\n ");//parte ja sofreu dano
		return 1; //para identificar um local q ja sofreu dano
	}*/

	//bloco de codigo responsavel pelas cabecas verticais

	// INICIO
	if((aux->barcoC)->tipo=='^'){//1 corresponde ao tipo ^
		((*h)->barcoC)->dano=1;//coloco o dano na estrutura
		while((aux->barcoC)->tipo !='V'){//2 corresponde ao tipo v
			aux=aux->baixo;
		}
		mapa *aux2=*h;//aux2 q vai percorrer para encontrar danos
		unsigned short int todo=1;//variavel para ver se todo o barco sofreu dano 1 se s 0 se n 
		while((aux2->barcoC)->tipo !='V'){
			aux2=aux2->baixo;
			if((aux2->barcoC)->dano!=1){
				todo=0;
			}
		}
		if(todo==0){//ainda tem partes sem dano
			printf("tiramos uma parte da existencia daquela embarcaco\n");
			(*h)->valorC='*';
		}else{
			printf("Kill exp +100\nvc destruiu aquele desnaturado\n"); 
			aux2=(*h)->baixo; //ele vai percorrer o meio do barco para mudar o show
			while((aux2->barcoC)->tipo !='V'){
				aux2->valorH='#';
				aux2=aux2->baixo;
			}
			(*h)->valorC='^';//mudancas nas extremidades
			aux->valorC='v';
			return HUMANO;//tipo de retorno q identifica acerto
		}
	}


	if((aux->barcoC)->tipo=='V'){//2 corresponde ao tipo v
		((*h)->barcoC)->dano=1;//coloco o dano na estrutura
		while((aux->barcoC)->tipo !='^'){//1 corresponde ao tipo ^
			aux=aux->cima;
		}
		mapa *aux2=*h;//aux2 q vai percorrer para encontrar danos
		unsigned short int todo=1;//variavel para ver se todo o barco sofreu dano 1 se s 0 se n 
		while((aux2->barcoC)->tipo !='^'){
			aux2=aux2->cima;
			if((aux2->barcoC)->dano!=1){
				todo=0;
			}
		}
		if(todo==0){//ainda tem partes sem dano
			printf("tiramos uma parte da existencia daquela embarcaco\n");
			(*h)->valorC='*';
		}else{
			printf("Kill exp +100\nvc destruiu aquele desnaturado\n"); 
			aux2=(*h)->cima; //ele vai percorrer o meio do barco para mudar o show
			while((aux2->barcoC)->tipo !='V'){
				aux2->valorH='#';
				aux2=aux2->cima;
			}
			(*h)->valorC='v';//mudancas nas extremidades
			aux->valorC='^';
			return HUMANO;//tipo de retorno q identifica acerto
		}
	}
		
		// FIM
		// BLOCO RESPONSAVEL PELAS CABECAS HORIZONTAIS
		//INICIO

	if((aux->barcoC)->tipo=='<'){//3 corresponde ao tipo <
		((*h)->barcoC)->dano=1;//coloco o dano na estrutura
		while((aux->barcoC)->tipo !='>'){//4 corresponde ao tipo >
			aux=aux->dir;
		}
		mapa *aux2=*h;//aux2 q vai percorrer para encontrar danos
		unsigned short int todo=1;//variavel para ver se todo o barco sofreu dano 1 se s 0 se n 
		while((aux2->barcoC)->tipo !='>'){
			aux2=aux2->dir;
			if((aux2->barcoC)->dano!=1){
				todo=0;
			}
		}
		if(todo==0){//ainda tem partes sem dano
			printf("tiramos uma parte da existencia daquela embarcaco\n");
			(*h)->valorC='*';
		}else{
			printf("Kill exp +100\nvc destruiu aquele desnaturado\n"); 
			aux2=(*h)->dir; //ele vai percorrer o meio do barco para mudar o show
			while((aux2->barcoC)->tipo !='>'){
				aux2->valorC='#';
				aux2=aux2->dir;
			}
			(*h)->valorC='<';//mudancas nas extremidades
			aux->valorC='>';
			return HUMANO;//tipo de retorno q identifica acerto
		}
	}
	
	if((aux->barcoC)->tipo=='>'){//4 corresponde ao tipo >
		((*h)->barcoC)->dano=1;//coloco o dano na estrutura
		while((aux->barcoC)->tipo !='<'){//3 corresponde ao tipo <
			aux=aux->esq;
		}
		mapa *aux2=*h;//aux2 q vai percorrer para encontrar danos
		unsigned short int todo=1;//variavel para ver se todo o barco sofreu dano 1 se s 0 se n 
		while((aux2->barcoC)->tipo !='<'){
			aux2=aux2->esq;
			if((aux2->barcoC)->dano!=1){
				todo=0;
			}
		}
		if(todo==0){//ainda tem partes sem dano
			printf("tiramos uma parte da existencia daquela embarcaco\n");
			(*h)->valorC='*';
		}else{
			printf("Kill exp +100\nvc destruiu aquele desnaturado\n"); 
			aux2=(*h)->esq; //ele vai percorrer o meio do barco para mudar o show
			while((aux2->barcoC)->tipo !='<'){
				aux2->valorC='#';
				aux2=aux2->esq;
			}
			(*h)->valorC='>';//mudancas nas extremidades
			aux->valorC='<';
			return HUMANO;//tipo de retorno q identifica acerto
		}
	}

	//FIM

	//AGORA O CASO DA POUPA
	//INICIO

	if((aux->barcoC)->tipo=='#'){//5 identifica o #
		((*h)->barcoC)->dano=1; //coloco o dano na area
		mapa *aux2=*h;//aux2 vai fixar na outra extremidade
		if((aux->barcoC)->pos==1){//inclinacao 1 indica ser vertical
			while((aux->barcoC)->tipo!='^'){//tipo 1 ^ e aux ira fixar la
				aux=aux->cima;
			}
			while((aux2->barcoC)->tipo!='v'){//tipo 2 v e aux2 ira fixar la
				aux2=aux2->baixo;
			}
			//agora temos es extremidades definidas
			mapa *aux3=aux;//vai percorrer em busca de danos
			unsigned short int todo=1;//vai ver se todo o barco foi abatido 1 se s 0 se n
			while((aux3->barcoC)->tipo!='v'){//tipo v
				aux3=aux3->baixo;
				if((aux3->barcoC)->dano!=1){
					todo=0;
				}
			}
			if(todo==0){
				printf("tiramos parte da existencia do desnaturado\n");
				(*h)->valorC='*';
			}else{
				aux3=aux->baixo;//aux3 vai para o primeiro bloco abaixo da cabeca superior do navio ^
				while((aux3->barcoC)->tipo !='v'){
					aux3->valorC='#';
					aux3=aux3->baixo;
				}
				//agora basta mudar as cabecas
				aux->valorC='^';
				aux2->valorC='v';
				printf("kill exp +100\nfoi pra vala");
			}
		}else{//se refere a inclinacao
			while((aux->barcoC)->tipo!='<'){//tipo 3 < e aux ira fixar la
				aux=aux->esq;
			}
			while((aux2->barcoC)->tipo!='>'){//tipo 4 > e aux2 ira fixar la
				aux=aux->dir;
			}
			//agora temos es extremidades definidas
			mapa *aux3=aux;//vai percorrer em busca de danos
			unsigned short int todo=1;//vai ver se todo o barco foi abatido 1 se s 0 se n
			while((aux3->barcoC)->tipo!='>'){//tipo >
				aux3=aux3->dir;
				if((aux3->barcoC)->dano!=1){
					todo=0;
				}
			}
			if(todo==0){
				printf("tiramos parte da existencia do desnaturado\n");
				(*h)->valorC='*';
				}else{
					aux3=aux->dir;//aux3 vai para o primeiro bloco abaixo da cabeca superior do navio ^
					while((aux3->barcoC)->tipo !='<'){
						aux3->valorC='#';
						aux3=aux3->dir;
					}
					//agora basta mudar as cabecas
					aux->valorC='<';
					aux2->valorC='>';
					printf("kill exp +100\nfoi pra vala");
					return HUMANO;

				}
			}
		}
	
		if((aux->barcoC)->tipo=='@'){
			(aux->barcoC)->dano=1;
			aux->valorC='@';
			return HUMANO;
		}
		if((aux->barcoC)->tipo=='&'){
			(aux->barcoC)->dano=1;
			aux->valorC='&';
			if(((submarinos->subH1)->barcoH)->dano==0){
				((submarinos->subH1)->barcoH)->dano=1;
				(submarinos->subH1)->valorH='&';
				printf("acertamos o nosso x9!\n");
			}
			if(((submarinos->subH2)->barcoH)->dano==0){
				((submarinos->subH2)->barcoH)->dano=1;
				(submarinos->subH2)->valorH='&';
				printf("acertamos o nosso x9!\n");
			}
			return COMPUTADOR;
		}
	}/*else{
		if(aux->barcoH==NULL){
			aux->valorH='O';//essa parte show sera exibida no print do mapa
			return HUMANO;//para identificar um acerto no mar
		}

		if((aux->barcoH)->dano==1){
			if((aux->barcoH)->tipo=='&'){
				(aux->barcoH)->dano=1;
				aux->valorH='*';
				if(((submarinos->subC1)->barcoC)->dano==0){
					((submarinos->subC1)->barcoC)->dano=1;
					(submarinos->subC1)->valorC='&';
					printf("acertaram o x9 deles huehuehue!\n");
				}
				if(((submarinos->subC2)->barcoC)->dano==0){
					((submarinos->subC2)->barcoC)->dano=1;
					(submarinos->subC2)->valorC='&';
					printf("acertaram o x9 deles huehuehue!\n");
				}
				return HUMANO;
			}
			aux->valorH='*';
			printf("aquele maldito nos acertou \n");
			return COMPUTADOR;
		}
	}*/
}//fecha a funcao
