#include <stdio.h>
#include <stdlib.h>

typedef struct TipoElemento {
  int elemento;
  struct TipoElemento *proximo;
} Elemento;

typedef struct TipoPilha {
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

int top(Pilha *p, int *elemento)
{
  if (empty(p))
    return 0;
  *elemento = p->topo->elemento;
  return 1;
}

int push(Pilha *p, int elemento)
{
  Elemento *e = (Elemento *)malloc(sizeof(Elemento));
  if (e == NULL)
    return 0;
  e->elemento = elemento;
  e->proximo = p->topo;
  p->topo = e;
  return 1;
}

int pop(Pilha *p)
{
  if (empty(p))
    return 0;
  Elemento *e = p->topo;
  p->topo = e->proximo;
  free(e);
  return 1;
}

int main() {
  Pilha *p1 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *p2 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *p3 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *pAux1 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *pAux2 = (Pilha*)malloc(sizeof(Pilha));
  init(p1);
  init(p2);
  init(p3);
  init(pAux1);
  init(pAux2);

  int opcao = 0, valor;

  while(1) {
    printf("Escolha a opção: (0)Popular primeira pilha, (1)Seguir para próxima etapa: ");
    scanf("%d", &opcao);
    if(opcao) break;

    printf("Digite o número a ser empilhado: ");
    scanf("%d", &valor);
    push(p1, valor);
  }

  while(1) {
    printf("Escolha a opção: (0)Popular segunda pilha, (1)Seguir para próxima etapa: ");
    scanf("%d", &opcao);
    if(opcao) break;

    printf("Digite o número a ser empilhado: ");
    scanf("%d", &valor);
    push(p2, valor);
  }

  while(!empty(p1)) {
    int itemP1;
    top(p1, &itemP1);

    while(!empty(p2)) {
      int itemP2;
      top(p2, &itemP2);

      if(itemP1 == itemP2) {
        push(p3, itemP1);
        break;
      }
      push(pAux2, itemP2);
      pop(p2);
    }

    while(!empty(pAux2)) {
      int itemAux2;
      top(pAux2, &itemAux2);
      push(p2, itemAux2);
      pop(pAux2);
    }
    push(pAux1, itemP1);
    pop(p1);
  }

  while(!empty(pAux1)){
    int itemAux1;
    top(pAux1, &itemAux1);
    push(p1, itemAux1);
    pop(pAux1);
  }

  printf("Valores da pilha 1:\n");
  while(!empty(p1)) {
    int itemP1;
    top(p1, &itemP1);
    printf("%d\n", itemP1);
    pop(p1);
  }

  printf("Valores da pilha 2:\n");
  while(!empty(p2)) {
    int itemP2;
    top(p2, &itemP2);
    printf("%d\n", itemP2);
    pop(p2);
  }

  printf("Valores da pilha 3:\n");
  while(!empty(p3)) {
    int itemP3;
    top(p3, &itemP3);
    printf("%d\n", itemP3);
    pop(p3);
  }
}
