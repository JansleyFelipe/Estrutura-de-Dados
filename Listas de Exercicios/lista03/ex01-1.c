#include <stdio.h>
#include <stdlib.h>
#include "ex01.c"

int main(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    init(p);

    int opcao = 0, value, tam;

    while(1){
        printf("Escolha uma das opcoes:\n(0)Alocar inteiros na pilha;\n(1)Sair;\n");
        scanf("%d", &opcao);
        if(opcao) break;
        printf("\nDigite o numero que deseja alocar\n");
        scanf("%d", &value);
        push(p, value);
    }

    tam = size(p);
    printf("O tamanho da Pilha eh de %d\n", tam);

    showStack(p);
}
