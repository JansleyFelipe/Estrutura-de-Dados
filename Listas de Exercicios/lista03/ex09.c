#include "ex09.h"

Pilha* init(unsigned max){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p -> max = max;
    p -> topo = -1;
    p -> in = (int*)malloc(p -> max * sizeof(int));
    p -> out = (int*)malloc(p -> max * sizeof(int));
    return p;
}

int full(Pilha *p){
    return p -> topo == (p -> max - 1);
}

int empty(Pilha *p){
    return p -> topo == -1;
}

int push(Pilha *p, int in, int out){
    if(full(p))
        return 0;
    p -> topo++;
    p -> in[p -> topo] = in;
    p -> out[p -> topo] = out;
    return 1;
}

int pop(Pilha *p){
    if(empty(p))
        return 0;
    p -> topo--;
    //*elemento = p -> elemento[p -> topo + 1];
    return 1;
}
int pop(Pilha *p, int *elemento){
    if(empty(p))
        return 0;
    p -> topo--;
    *elemento = p -> elemento[p -> topo + 1];
    return 1;
}
