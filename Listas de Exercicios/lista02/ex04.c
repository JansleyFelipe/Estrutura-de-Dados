#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElemento{
  int elemento;
  struct tipoElemento *proximoPar;
  struct tipoElemento *proximoImpar;
}Elemento;

typedef struct tipoPilha{
  Elemento *topoPar;
  Elemento *topoImpar;
}Pilha;

void init(Pilha *p){
  p->topoPar = NULL;
  p->topoImpar = NULL;
}

int empty(Pilha *p, int i){
  if(i){
    return p->topoImpar == NULL;
    }
    else{
      return p->topoPar == NULL;
    }
}

int top(Pilha *p, int i, int *elemento){
  if(i){
    if(empty(p, i))
      return 0;
    *elemento = p->topoImpar->elemento;
  }
  else{
    if(empty(p, i))
      return 0;
    *elemento = p->topoPar->elemento;
  }
  return 1;
}

int push(Pilha *p, int elemento){
  Elemento *e = (Elemento*)malloc(sizeof(Elemento));
  if(e == NULL)
    return 0;
  if(elemento%2 == 0){
    e->elemento = elemento;
    e->proximoPar = p->topoPar;
    p->topoPar = e;
  }
  else{
    e->elemento = elemento;
    e->proximoImpar = p->topoImpar;
    p->topoImpar = e;
  }
  return 1;
}

int pop(Pilha *p, int i){
  Elemento *e;
  if(i){
    if(empty(p, i))
      return 0;
    e = p->topoImpar;
    p->topoImpar = e->proximoImpar;
    free(e);
  }
  else{
    if(empty(p, i))
      return 0;
    e = p->topoPar;
    p->topoPar = e->proximoPar;
    free(e);
  }
  return 1;
}
//Na funcao count(), alem de contar quantos numeros impares e pares a pilha possui, eu ja fiz ele imprimir. Como eu vou desempilhando e imprimindo acaba aparecendo a pilha inversa na hora que da o printf
void count(Pilha *p, int *totalPar, int *totalImpar){
  int countPar = 0, countImpar = 0;

  while(!empty(p, 0)){
    int auxPar;
    top(p, 0, &auxPar);
    pop(p, 0);
    printf("%d\n", auxPar);
    countPar++;
  }

  while(!empty(p, 1)){
    int auxImp;
    top(p, 1, &auxImp);
    pop(p, 1);
    printf("%d\n", auxImp);
    countImpar++;
  }

  *totalPar = countPar;
  *totalImpar = countImpar;

}


int main(){
  Pilha *p = (Pilha*)malloc(sizeof(Pilha));

  int opcao = 0, value, totalPar, totalImpar;
  while(1){
    printf("\n\nEscolha uma opcao: (0)Alocar numeros inteiros na pilha; (1)Parar de Alocar: ");
    scanf("%d", &opcao);
    if(opcao) break;

    printf("\nDigite o numero que deseja alocar\n");
    scanf("%d", &value);
    push(p, value);
  }
  count(p, &totalPar, &totalImpar);
  printf("\n\n A pilha possui %d numeros pares e %d numeros impares\n", totalPar, totalImpar);
}
