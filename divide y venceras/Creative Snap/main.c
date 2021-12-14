#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

long long int n;
long long int k;
long long int a;
long long int b;
long long int* lista;

long long int analizar(long long int divisiones, long long int posicion);
int ordenar(long long int** lista, int tamano);

int main(int argc, char const *argv[]){
    long long int i;
    long long int tmp = 0;
    long long int tamano;
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%lld",&a);
    scanf("%lld",&b);
    
    lista = (long long int*) calloc(k,sizeof(long long int));
    
    for (i = 0; i < k; i++){
        scanf("%lld",&tmp);
        lista[i] = tmp;
    }
    ordenar(&lista,k);
    
    printf("%lld",analizar(0,0));
    return 0;
}

long long int analizar(long long int divisiones, long long int posicion){
    long long int resultado = 0;
    long long int i = 0;

    float mayor = pow(2,(n-divisiones))*posicion + pow(2,(n-divisiones));
    float menor = pow(2,(n-divisiones))*posicion;

    int llego = 1;
    do{
        if ( menor <= lista[i]-1 && mayor  > lista[i]-1){
            resultado++;
        }else if(mayor  < lista[i]-1){
            llego = 0;
        }
        i++;
    }while (llego && i <= k+1);
       
    if (resultado == 0){
        resultado = a;
    }else{
        resultado = b*resultado*pow(2,(n-divisiones));
    }

    if (divisiones == n || resultado == a){
        return resultado;
    }else{
        long long int izquierda = analizar(divisiones+1,(posicion*2));
        long long int derecha = analizar(divisiones+1,(posicion*2)+1);
        
        
        return MIN(resultado,  izquierda + derecha);
    }
}

int ordenar(long long int** lista, int tamano){
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