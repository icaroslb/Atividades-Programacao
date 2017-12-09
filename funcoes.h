#define TAMMAPAX 12
#define TAMMAPAY 12

#define HORIZONTAL 0
#define VERTICAL 1

#define HUMANO 0
#define COMPUTADOR 1

#define JANGADA 0
#define SUBMARINO 1
#define FRAGATA 2
#define DESTROYER 3
#define PORTA_AVIAO 5

typedef struct Embar{
	unsigned short int parte, tipo, pos, dano;
} embar;

typedef struct Mapa{
	unsigned short int x, y, valorH, valorC;
	embar *barcoH, *barcoC;
	struct Mapa *cima, *baixo, *esq, *dir;
} mapa;

typedef struct Sub{
	mapa *subH1, *subH2, *subC1, *subC2;
} sub;

//Funções mapas
	//função que inicializa um nó do mapa
	void iniciNo(mapa **, unsigned short int, unsigned short int);
	//função que iniciliza o mapa
	void inicializar_mapa(mapa **, sub *);
	//"Caminha" o ponteiro a posição x e y requerida e retorna na posição certa
	mapa* caminhar(mapa *, unsigned short int, unsigned short int);
	//Imprime na tela os mapas
	void mostrar_mapa(mapa *, mapa **);
	//Reinicia os valores do mapa
	void reiniciar_mapa(mapa *);
	//Libera o espaço do mapa
	void limpar_mapa(mapa **);

//Funções barcos
	//Inicializa os valores do barco
	void inicializar_barco(mapa *, unsigned short int,  unsigned short int, unsigned short int, unsigned short int);
	//Cria os barcos
	void criar_barco(mapa *, unsigned short int, unsigned short int, unsigned short int);
	/*Analisa se o local é válido
	para se colocar o barco*/
	unsigned short int pos_vali(mapa *, unsigned short int, unsigned short int, unsigned short int);
	//Iniciliza os barcos no mapa
	void barco_mapa(mapa *, sub *);
	
//Funções entrada
	//Essa função faz a verificação de uma entrada passada para ela,
	//retorna 0 se for uma entrada inválida e 1 se for válida
	void limpar_teclado();
	unsigned short int leitura(unsigned short int *, unsigned short int *);
	void entrada(unsigned short int *, unsigned short int *);
	unsigned short int destruido(mapa *, unsigned short int);
	void jangada_destruida(sub *, unsigned short int);
	unsigned short int tiro(mapa *, sub *, unsigned short int);
	
//Funções de jogada do computador
	//Essa função faz as decisões do computador jogar,
	//ela retornar COMPUTADOR se ele puder jogar novamente
	//e HUMANO se for a vez do usuário
	unsigned short int decisao(mapa **, sub *, unsigned short int);
