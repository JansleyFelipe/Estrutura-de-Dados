#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex08.c"

int main(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    init(p);
    char last[20], newOne[20], noSpace[20], padrao[20] = "FACE";
    int n, i, winners = 0;

    printf("Numero de participantes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Participante numero %d, digite na ordem que desejar as quatro letras que recebeu: ", i);
        fflush(stdin);
        fgets(newOne, 20, stdin);
        int count = 0;
        for(int j = 0; newOne[j] != '\0'; j++){
            if(newOne[j] != ' '){
              noSpace[count++] = newOne[j];
            }
        }
        printf("%s\n\n", noSpace);

        if(empty(p)){
            strcpy(last, padrao);
            for(i = 0; padrao[i] != '\0'; i++)
                push(p, padrao[i]);
        }
        ifWin(p, noSpace, last, &winners);
    }
    printf("\n\n%d participantes ganharam\n", winners);
    return 0;
}
