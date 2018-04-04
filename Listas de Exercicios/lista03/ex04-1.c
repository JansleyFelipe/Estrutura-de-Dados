#include <stdio.h>
#include <stdlib.h>
#include "ex04.c"

int main(){
    Pilha *p;
    char opcao[20];
    int retorno;

    init(p);

    printf("Digite os caracteres em uma string para:\n(+)Para alocar um numero inteiro aleatorio na Pilha;\n(-)Para desempilhar;");

    scanf("%s", opcao);

    retorno = doWhat(p, opcao);
    if(retorno == 0)
        printf("Overflow\n");
    if(retorno == -1)
        printf("Underflow\n");

    return 0;
}
