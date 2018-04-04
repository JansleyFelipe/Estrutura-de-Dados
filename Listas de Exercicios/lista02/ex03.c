#include <stdio.h>
#include <stdlib.h>

typedef struct TipoElemento{
  int elemento;
  struct TipoElemento *proximo;
}Elemento;

typedef struct tipoPilha{
  Elemento *topo;
}Pilha;

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
  Elemento *e = (Elemento *)malloc(sizeof(Elemento));
  if(e == NULL)
    return 0;
  e->elemento = elemento;
  e->proximo = p->topo;
  p->topo = e;
  return 1;
}

int pop(Pilha *p){
  if(empty(p))
     return 0;
  Elemento *e = p->topo;
  p->topo = e->proximo;
  free(e);
  return 1;
}

int main(){
  Pilha *p = (Pilha*)malloc(sizeof(Pilha));
  Pilha *pImpar = (Pilha*)malloc(sizeof(Pilha));
  Pilha *pPar = (Pilha*)malloc(sizeof(Pilha));

  init(p);
  init(pImpar);
  init(pPar);

  int n, opcao = 0;

  while(1){
    printf("Escolha uma das opcoes: (0)Alocar inteiro na Pilha; (1)Parar de Alocar: ");
    scanf("%d", &opcao);
    if(opcao) break;

    printf("Digite o valor a ser alocado na pilha\n");
    scanf("%d", &n);
    push(p, n);
  }

  //Exibicao da pilha antes de estar ordenada com pares na base
  printf("\n\nPrimeira pilha antes de estar ordenadas com pares na base\n");
  while(!empty(p)){
    int aux;
    top(p, &aux);

    printf("%d\n", aux);

    pop(p);
    if(aux%2 == 0){
      push(pPar, aux);
    }
    else{
      push(pImpar, aux);
    }
  }

  printf("\nPilha par\n");
  while(!empty(pPar)){
    int auxP;
    top(pPar, &auxP);

    printf("%d\n", auxP);

    pop(pPar);
    push(p, auxP);
  }

  printf("\nPilha impar\n");
  while(!empty(pImpar)){
    int auxI;
    top(pImpar, &auxI);

    printf("%d\n", auxI);

    pop(pImpar);
    push(p, auxI);
  }

  printf("\nPilha ja ordenada\n");
  while(!empty(p)){
    int auxF;
    top(p, &auxF);
    pop(p);
    printf("%d\n", auxF);
  }
}
