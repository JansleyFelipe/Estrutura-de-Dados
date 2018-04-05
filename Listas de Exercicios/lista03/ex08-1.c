#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex08.c"

int main()
{
    Pilha *p = init();

    char last[20], newOne[20], noSpace[20], padrao[20] = "FACE";
    int n, i, j, b, winners = 0;

    printf("Numero de participantes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Participante numero %d, digite na ordem que desejar as quatro letras que recebeu: ", i + 1);
        fflush(stdin);
        fgets(newOne, 20, stdin);
        int count = 0;
        for(j = 0; newOne[j] != '\0'; j++)
        {
            if(newOne[j] != ' ')
            {
                noSpace[count++] = newOne[j];
            }
        }

        if(empty(p))
        {
            for(b = 0; padrao[b] != '\0'; b++)
                push(p, padrao[b]);
        }

        ifWin(p, noSpace, last, &winners);
    }
    printf("\n\n%d participantes ganharam\n", winners);
    return 0;
}