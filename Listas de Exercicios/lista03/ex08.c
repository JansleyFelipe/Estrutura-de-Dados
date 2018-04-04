#include "ex08.h"

void init(Pilha *p){
    p->topo = NULL;
}

int empty(Pilha *p){
    if(p->topo == NULL)
        return 1;
    return 0;
}

int pop(Pilha *p){
    if(empty(p))
        return 0;
    Elemento *e = p->topo;
    p->topo = e->next;
    //*elemento = e->elemento;
    free(e);
    return 1;
}

int push(Pilha *p, char elemento){
    Elemento *e = (Elemento*)malloc(sizeof(Elemento));
    if(e == NULL)
        return 0;
    e->elemento = elemento;
    e->next = p->topo;
    p->topo = e;
    return 1;
}

int ifWin(Pilha *p, char *s, char *last, int *winners){
    int i, count = 0;
    char inverso[20];

    for(i = strlen(last) - 1; i >= 0; i--){
        inverso[count] = last[i];
        count++;
        continue;
    }

        if(strcmp(inverso, s) == 0){
            *winners += 1;
            for(i = 0; last[i] != '\0'; i++)
                pop(p);
            }else{
                for(i = 0; s[i] != '\0'; i++)
                    push(p, s[i]);
                strcpy(last, s);
            }
}
