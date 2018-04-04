#include "ex04.h"

void init(Pilha *p){
    p->topo = -1;
}

int full(Pilha *p){
    if(p->topo == MAX - 1)
        return 1;
    return 0;
}

int vazio(Pilha *p){
    if(p->topo == -1)
        return 1;
    return 0;
}

int push(Pilha *p, int elemento){
    if(full(p))
        return 0;
    p->topo++;
    p->elemento[p->topo] = elemento;
    return 1;
}

int pop(Pilha *p){
    if(vazio(p))
        return 0;
    p->topo--;
    //**elemento = p->elemento[p->topo + 1];
    return 1;
}

int doWhat(Pilha *p, char s[20]){
    int i, elemento;

    for(i = 0; s[i] != '\0'; i++){
         if(s[i] == '+'){
            if(full(p)){
                return 0;
            }else{
                elemento = rand() % 25;
                push(p, elemento);
            }
         }
         else{
            if(vazio(p)){
                return -1;
            }else{
                pop(p);
            }
         }
    }
    return 1;
}
