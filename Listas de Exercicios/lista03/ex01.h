typedef struct tipoElemento{
	int elemento;
	struct tipoElemento *next;
}Elemento;

typedef struct tipoPilha{
	Elemento *topo;
}Pilha;

void init(Pilha *p);

int empty(Pilha *p);

int top(Pilha *p, int *elemento);

int push(Pilha *p, int elemento);

int pop(Pilha *p);

int size(Pilha *p);

int showStack(Pilha *p);
