#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void inicializar_barco(mapa *m, unsigned short int tipo,  unsigned short int pos, unsigned short int valor, unsigned short int jogador){
	if(jogador==HUMANO){
		m->barcoH=(embar*)malloc(sizeof(embar));
		(m->barcoH)->parte=valor;
		m->valorH=valor;
		(m->barcoH)->pos=pos;
	}else{
		m->barcoC=(embar*)malloc(sizeof(embar));
		(m->barcoC)->parte=valor;
		m->valorC=valor;
		(m->barcoC)->pos=pos;
	}
}

//Cria os barcos
void criar_barco(mapa *m, unsigned short int tipo, unsigned short int pos, unsigned short int jogador){
	unsigned short int aux;
	
	//Cria barco do humano
	if(jogador==HUMANO){
		if(tipo==JANGADA){
			//Cria a jangada
			inicializar_barco(m, tipo, pos, '&', jogador);
		}else if(tipo==SUBMARINO){
			//Cria o submarino
			inicializar_barco(m, tipo, pos, '@', jogador);
		}else{
			//Cria a primeira parte do barco
			if(pos==HORIZONTAL){
				inicializar_barco(m, tipo, pos, '<', jogador);
				m=m->dir;
			}else{
				inicializar_barco(m, tipo, pos, '^', jogador);
				m=m->baixo;
			}
			//Cria a poupa do barco
			for(aux=1; aux<tipo-1; aux++){
				inicializar_barco(m, tipo, pos, '#', jogador);
				if(pos==HORIZONTAL){m=m->dir;}
				else{m=m->baixo;}
			}
			//Cria a última parte do barco
			if(pos==HORIZONTAL){
				inicializar_barco(m, tipo, pos, '>', jogador);
			}else{
				inicializar_barco(m, tipo, pos, 'v', jogador);
			}
		}
	}else{
		//Cria barco do computador
		if(tipo==JANGADA){
			//Cria a jangada
			inicializar_barco(m, tipo, pos, '&', jogador);
		}else if(tipo==SUBMARINO){
			//Cria o submarino
			inicializar_barco(m, tipo, pos, '@', jogador);
		}else{
			//Cria a primeira parte do barco
			if(pos==HORIZONTAL){
				inicializar_barco(m, tipo, pos, '<', jogador);
				m=m->dir;
			}else{
				inicializar_barco(m, tipo, pos, '^', jogador);
				m=m->baixo;
			}
			//Cria a poupa do barco
			for(aux=1; aux<tipo-1; aux++){
				inicializar_barco(m, tipo, pos, '#', jogador);
				if(pos==HORIZONTAL){m=m->dir;}
				else{m=m->baixo;}
			}
			//Cria a última parte do barco
			if(pos==HORIZONTAL){
				inicializar_barco(m, tipo, pos, '>', jogador);
			}else{
				inicializar_barco(m, tipo, pos, 'v', jogador);
			}
		}
	}
}

//Analisar local válido
unsigned short int pos_vali(mapa *m, unsigned short int tipo, unsigned short int pos, unsigned short int humcomp){
	unsigned short int ind;
	for(ind=0; ind<=tipo-1; ind++){
		if(humcomp==HUMANO && m->barcoH!=NULL){
			return 0;
		}else if(humcomp==COMPUTADOR && m->barcoC!=NULL){
			return 0;
		}
		if(pos==HORIZONTAL){
			m=m->dir;
		}else{
			m=m->baixo;
		}
	}
	return 1;
}

//Iniciliza os barcos no mapa
void inicializar_barcos(mapa *m){
	unsigned short int x, y, pos, aux, humcomp;
	
	srand(time(NULL));
	for(humcomp=HUMANO; humcomp<=COMPUTADOR; humcomp++){
		//Jangada
		x=rand()%TAMMAPAX;
		y=rand()%TAMMAPAY;
		m=caminhar(m, x, y);
		pos=rand()%2;
		criar_barco(m, JANGADA, pos, humcomp);
		//Submarino
		aux=0;
		while(aux<2){
			x=rand()%TAMMAPAX;
			y=rand()%TAMMAPAY;
			m=caminhar(m, x, y);
			pos=rand()%2;
			if(pos_vali(m, SUBMARINO, pos, humcomp)){
				criar_barco(m, SUBMARINO, pos, humcomp);
				aux+=1;
			}
		}
		//Fragata
		aux=0;
		while(aux<3){
			pos=rand()%2;
			if(pos==HORIZONTAL){
				x=rand()%(TAMMAPAX);
				y=rand()%(TAMMAPAY-FRAGATA);
			}else{
				x=rand()%(TAMMAPAX-FRAGATA);
				y=rand()%(TAMMAPAY);
			}
			m=caminhar(m, x, y);
			if(pos_vali(m, FRAGATA, pos, humcomp)){
				criar_barco(m, FRAGATA, pos, humcomp);
				aux+=1;
			}
		}
		//Destroyers
		aux=0;
		while(aux<2){
			pos=rand()%2;
			if(pos==HORIZONTAL){
				x=rand()%(TAMMAPAX);
				y=rand()%(TAMMAPAY-DESTROYER);
			}else{
				x=rand()%(TAMMAPAX-DESTROYER);
				y=rand()%(TAMMAPAY);
			}
			m=caminhar(m, x, y);
			if(pos_vali(m, DESTROYER, pos, humcomp)){
				criar_barco(m, DESTROYER, pos, humcomp);
				aux+=1;
			}
		}
		//Porta Aviões
		aux=0;
		while(aux<1){
			pos=rand()%2;
			if(pos==HORIZONTAL){
				x=rand()%(TAMMAPAX);
				y=rand()%(TAMMAPAY-PORTA_AVIAO);
			}else{
				x=rand()%(TAMMAPAX-PORTA_AVIAO);
				y=rand()%(TAMMAPAY);
			}
			m=caminhar(m, x, y);
			if(pos_vali(m, PORTA_AVIAO, pos, humcomp)){
				criar_barco(m, PORTA_AVIAO, pos, humcomp);
				aux+=1;
			}
		}
	}
}
