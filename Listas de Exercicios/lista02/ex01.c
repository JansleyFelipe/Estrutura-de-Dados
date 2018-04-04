#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoElemento
{
  char elemento;
  struct TipoElemento *proximo;
} Elemento;

typedef struct TipoPilha
{
  Elemento *topo;
} Pilha;

void init(Pilha *p)
{
  p->topo = NULL;
}

int empty(Pilha *p)
{
  return p->topo == NULL;
}

int push(Pilha *p, char elemento)
{
  Elemento *e = (Elemento *)malloc(sizeof(Elemento));
  if (e == NULL)
    return 0;
  e->elemento = elemento;
  e->proximo = p->topo;
  p->topo = e;
  return 1;
}

int pop(Pilha *p, char *elemento)
{
  if (empty(p))
    return 0;
  Elemento *e = p->topo;
  *elemento = e->elemento;
  p->topo = e->proximo;
  free(e);
  return 1;
}

int main()
{
  Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  init(p);
  char mina[1000];
  int n;

  printf("Quantos casos de teste deseja fazer?\n");
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int diamante = 0;
    printf("Digite a expressao\n");
    scanf("%s", mina);

    for(int j = 0; j < strlen(mina); j++) {
      if(mina[j] != '>') {
        push(p, mina[j]);
      } else {
        char *aux;
        while(!empty(p)) {
          pop(p, aux);
          if(*aux == '<'){
            diamante++;
            break;
          }
        }
      }
    }
    printf("Possui %d diamante(s)\n", diamante);
  }
  return 0;
}
