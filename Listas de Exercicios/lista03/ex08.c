#include "ex08.h"

Pilha * init()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int empty(Pilha *p)
{
    if(p->topo == NULL)
        return 1;
    return 0;
}

int pop(Pilha *p)
{
    if(empty(p))
        return 0;
    Elemento *e = p->topo;
    p->topo = e->next;
    //*elemento = e->elemento;
    free(e);
    return 1;
}

int push(Pilha *p, char elemento)
{
    Elemento *e = (Elemento*)malloc(sizeof(Elemento));
    if(e == NULL)
        return 0;
    e->elemento = elemento;
    e->next = p->topo;
    p->topo = e;
    return 1;
}

int ifWin(Pilha *p, char s[], char last[], int *winners)
{
    int i, count = 0;

    Elemento *e = p->topo;
    for(i = 0; i < 4; i++)
    {
        if(e->elemento == s[i])
        {
            count++;
        }
        e = e->next;
    }
    if(count == 4)
    {
        *winners += 1;
        for(i = 0; i < 4; i++)
        {
            pop(p);
        }
    }
   else
    {
        for(i = 0; i < 4; i++)
        {
            push(p,s[i]);
        }
    }

}
