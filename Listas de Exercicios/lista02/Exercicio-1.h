#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaDiamante{
	char *s;
	struct pilhaDiamate *next;
}pilhaDiamante;

typedef struct Pilha{
	pilhaDiamante *topo;
}Pilha;

void init(Pilha *p);

int empty(Pilha *p);

int top(Pilha *p, int *elemento);

int push(Pilha *p, int element);

int pop(Pilha *p, int elemento);