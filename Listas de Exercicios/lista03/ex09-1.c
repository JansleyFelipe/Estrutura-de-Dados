#include <stdio.h>
#include <stdlib.h>
#include "ex09.c"

int main(){
    int i, drivers, size, in = 0, out = 0, lastIn = 0, lastOut = 0, worked = 1, fullIn, fullOut;

    printf("Digite o numero de motoristas e o tamanho do estacionamento: ");
    scanf("%d%d", &drivers, &size);

    Pilha *p = init(size);

    for(i = 0; i < drivers; i++){
        printf("Digite o horário de entrada e saida do motorista: ");
        scanf("%d%d", &in, &out);
        
        if(in < lastOut)
            worked = 0;
        if(!full(p)){
            lastIn = in;
            lastOut = out;
            push(p, in, out);
            
        }
        
        if(full(p)){
            if(in > lastOut){
                pop(p);
                pop(p);
                push(p, in);
                push(p, out);
                lastIn = in;
                lastOut = out;
                if(in < lastOut)
                    worked = 0;
            }
        }
    }

    return 0;
}