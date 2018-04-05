typedef struct tipoElemento{
    char elemento;
    struct tipoElemento *next;
}Elemento;

typedef struct tipoPilha{
    Elemento *topo;
}Pilha;

Pilha * init();
int empty(Pilha *p);
int pop(Pilha *p);
int push(Pilha *p, char elemento);
int ifWin(Pilha *p, char s[], char last[], int *winners);
