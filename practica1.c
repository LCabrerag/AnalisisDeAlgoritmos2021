#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[5];
    int orden[5];
    int i,j;
    int tmp;

    srand(5);
    for (i = 0;i < 5; i++){
        numeros[i] = rand()%(10001);
    }
    
    
    tmp = numeros[0];
    for (i = 0;i < 5; i++){
        if (tmp > numeros[i]){
            tmp = numeros[i];
        }        
    }
    orden[0] = tmp;

    for (i = 1; i < 5; i++){
        tmp = 10000;
        for (j = 0;j < 5; j++){
            if (tmp > numeros[j] && numeros[j] > orden[i-1]){
                tmp = numeros[j];
            }
        }
        orden[i] = tmp;
    }
    
    printf("numeros sin ordenar: %d %d %d %d %d \n",numeros[0],numeros[1],numeros[2],numeros[3],numeros[4]);

    printf("numeros ordenados: %d %d %d %d %d ",orden[0],orden[1],orden[2],orden[3],orden[4]);

    return 0;
}