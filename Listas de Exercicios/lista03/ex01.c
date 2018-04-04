#include <stdlib.h>
#include "ex01.h"

void init(Pilha *p){
	p->topo = NULL;
}

int empty(Pilha *p){
	return p->topo == NULL;
}

int top(Pilha *p, int *elemento){
	if(empty(p))
		return 0;
	*elemento = p->topo->elemento;
	return 1;
}

int push(Pilha *p, int elemento){
	Elemento *e = (Elemento*)malloc(sizeof(Elemento));
	if(e == NULL)
		return 0;
	e->elemento = elemento;
	e->next = p->topo;
	p->topo = e;
	return 1;
}

int pop(Pilha *p){
	if(empty(p))
		return 0;
	Elemento *e = p->topo;
	p->topo = e->next;
	free(e);
	return 1;
}

int size(Pilha *p){
	Elemento *e = p->topo;;
	int count = 0;

	if(!empty(p))
		count++;

	while(e->next != NULL){
		count++;
		e = e->next;
	}
	return count;
}

int showStack(Pilha *p){
    Elemento *e = p->topo;

    if(!empty(p))
        printf("%d\n", e->elemento);
    else
        return 0;

    while(e->next != NULL){
        e = e->next;
        printf("%d\n", e->elemento);
    }
    return 1;
}

