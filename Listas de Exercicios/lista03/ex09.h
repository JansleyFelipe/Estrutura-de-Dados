typedef struct tipoElemento{
    int *in;
    int *out;
    unsigned max;
}Elemento;

typedef struct tipoPilha{
    Elemento *topo;
}




Pilha* init(unsigned max);
int full(Pilha *p);
int empty(Pilha *p);
int push(Pilha *p, int elemento);
int pop(Pilha *p);
int pop(Pilha *p, int *elemento);