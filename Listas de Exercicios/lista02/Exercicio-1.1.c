#include <stdio.h>
#include <stdlib.h>
#include "Exercicio-1.h"

int main(){
	char s[1000], aux;
	int diamante = 0, entrada, i, j = 0;
	
	scanf("%i", &entrada);
	
	for(i = 0; i < entrada; i++){
		Pilha encontrado;
		init(&encontrado);
		puts(s);
		
		while(s[j]!= '\0'){
			if(s[j] != '>')
				push(&encontrado, &aux);
			while(!empty(encontrado)){
				pop(&encontrado, &aux);
				if(aux == '<'){
					diamante++;
					break;
				}
			}
		}
		printf("%i Diamante(s) encontrado(s) no teste de caso %i\n", diamante, i + 1);
	}
	return 0;
}
				
		