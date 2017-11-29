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

void iniciNo(mapa **, unsigned short int, unsigned short int);
void inicializar_barco(mapa *, unsigned short int,  unsigned short int, unsigned short int, unsigned short int);
void criar_barco(mapa *, unsigned short int, unsigned short int, unsigned short int);
unsigned short int pos_vali(mapa *, unsigned short int, unsigned short int, unsigned short int);
void inicializar_barcos(mapa *);
void inicializar_mapa(mapa **);
mapa* caminhar(mapa *, unsigned short int, unsigned short int);
void mostrar_mapa(mapa *);
