#include <stdio.h>
#include <stdlib.h>
#include "Exercicio-1.h"

void init(Pilha *p){
	p -> topo = NULL;
}

int empty(Pilha *p){
	if(p -> topo == NULL)
		return 1;
	return 0;
}

int top(Pilha *p, int *elemento){
	if(empty(p))
		return 0;
	*elemento = p -> topo-> elemento;
	return 1;
}

int push(Pilha *p, int elemento){
	pilhaDiamante *e = (pilhaDiamante*) malloc(sizeof(pilhaDimante));
	if(e == NULL)
		return 0;
	
	e -> elemento = elemento;
	e -> next = p -> topo;
	p -> topo = e;
	return 1;
}

int pop(Pilha *p, int *elemento){
	if(empty(p))
		return 0;
	
	pilhaDiamante *e;
	e = p -> topo;
	*elemento = e -> elemento;
	p -> topo = p -> next;
	free(e);
}
		
		