#include <stdio.h>
#include <stdlib.h>

#define N_MAX 101

unsigned int fib3(unsigned int n, unsigned int *nchamadas, unsigned int resultados[]);

int main() {
    unsigned int num, result, nchamadas;
    unsigned int resultados[N_MAX] = {0};
   

    while(1) {
        do {
            printf("Numero? "); scanf("%d", &num);
            if(num > 100) printf("Escolha um numero entre 0 e 100");
        } while(num > 100);
        
        result = fib3(num, &nchamadas, resultados);
        
        if(resultados[num]==0) {
            resultados[num]= result;
        }
    
        // printf("fib() foi chamado %d vezes\n", nchamadas);
        printf("O numero de ordem  %d e %d\n", num, result);
    }
}

unsigned int fib3(unsigned int n, unsigned int *nchamadas, unsigned int resultados[]) {
    static int i=0;
    i++;
    *nchamadas = i;

    if(resultados[n] != 0) return resultados[n];
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib3(n-1, nchamadas, resultados) + fib3(n-2, nchamadas, resultados);
}