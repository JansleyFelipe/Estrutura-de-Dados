#define MAX 3

typedef struct pilha{
    int topo;
    int elemento[MAX];
}Pilha;

void init(Pilha *p);

int full(Pilha *p);

int vazio(Pilha *p);

int push(Pilha *p, int elemento);

int pop(Pilha *p);

int doWhat(Pilha *p, char s[20]);
