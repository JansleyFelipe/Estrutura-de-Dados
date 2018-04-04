#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaString{
	char *s;
	struct pilhaString *next;
}pilhaString;

typedef struct tipoPilha{
	pilhaString topo;
}Pilha;

void init(Pilha *p){
	p -> topo = NULL;
}

int push(char *s){
	char *p;
	pilhaString *q;

	if((p = malloc((strlen(s) + 1) * sizeof(char))) == NULL){
		printf("Out of memory\n");
		return 1;
		}
	strcpy(p, s);

	if((q = malloc(sizeof(pilhaString))) == NULL){
		printf("Out of memory!\n");
		return 1;
	}
	q -> s = p;
	q -> next = topo;
	topo = q;
}

char pop(){
	char *p;
	pilhaString *q;

	if(topo == NULL){
		printf("The Stack is empty\n");
		return NULL;
	}
	q = topo;
	topo = topo -> next;
	p = q -> s;
	free(q);
	return p;
}



