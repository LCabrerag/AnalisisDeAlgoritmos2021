
#include <stdio.h>
#include <stdlib.h>

void analizar(long long int* lista, long long int tamano);
void ordenar(long long int** lista, long long int tamano);

int main(int argc, char const *argv[]){
    long long int i,j;
    long long int n;
    long long int tmp;
    long long int pruebas;
    long long int* lista;

    scanf("%lld",&pruebas);
    for (i = 0; i < pruebas; i++){
        scanf("%lld",&n);
        lista = (long long int*) calloc(n,sizeof(long long int));
        for (j = 0; j < n; j++){
            scanf("%lld",&tmp);
            lista[j] = tmp;
        }
        analizar(lista, n);
        
    }
    

    return 0;
}

void analizar(long long int* lista, long long int tamano){
    long long int i=0,j,k;
    long long int x,y;
    long long int exitos = 0;
    int caso;
    ordenar(&lista,tamano);
    
    
    while (exitos < tamano/2){
        j=0;
        x = lista[tamano-i-1];
        for (k = 0; k < tamano-i-1; k++){        
            y = lista[k];
            caso = 1;
            for (j = 0; j < k; j++){
                if (x%y == lista[j]){
                    caso = 0;
                }
            }
            if (caso == 1 && exitos < tamano/2){
                exitos++;
                printf("%lld %lld ",x,y);
            }
        }
        i++;
    }
    
}

void ordenar(long long int** lista, long long int tamano){
    long long int i,j;
    long long int tmp;
    for (i = 0 ; i < tamano - 1; i++){
        for (j = 0 ; j < tamano - i - 1; j++){
            if ((*lista)[j] > (*lista)[j+1]){
                tmp = (*lista)[j];
                (*lista)[j]   = (*lista)[j+1];
                (*lista)[j+1] = tmp;
            }
        }
    }
}