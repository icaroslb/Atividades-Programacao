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
	unsigned short int parte, tipo, pos;
} embar;

typedef struct Mapa{
	unsigned short int x, y, valorH, valorC;
	embar *barcoH, *barcoC;
	struct Mapa *cima, *baixo, *esq, *dir;
} mapa;

//Funções mapas
	//função que inicializa um nó do mapa
	void iniciNo(mapa **, unsigned short int, unsigned short int);
	//função que iniciliza o mapa
	void inicializar_mapa(mapa **);
	//"Caminha" o ponteiro a posição requerida
	mapa* caminhar(mapa *, unsigned short int, unsigned short int);
	//Imprime na tela os mapas
	void mostrar_mapa(mapa *);
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
	void barco_mapa(mapa *);
