#define TamFila 100

typedef char elem;

typedef struct {
			int inicio, fim, total;
			elem itens[TamFila];
} Fila;

//operações básicas
void Cria(Fila*);
void Esvazia(Fila*);
int EstaVazia(Fila*);
int EstaCheia(Fila*);
void Entra(Fila*, elem*, int*);
void Sai(Fila*, elem*, int*);

//outras operações mais sofisticadas
int Crescente(Fila*);
elem Primeiro(Fila*, int*);
void Unir(Fila*, Fila*, Fila*, int*);
