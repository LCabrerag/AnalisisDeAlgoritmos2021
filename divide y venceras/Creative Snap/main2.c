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


int main(int argc, char const *argv[]){
    long long int i;
    long long int tmp = 0;
    long long int tamano;
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%lld",&a);
    scanf("%lld",&b);
    
    lista = (long long int*) calloc(pow(2,n),sizeof(long long int));
    
    
    for (i = 0; i < k; i++){
        scanf("%lld",&tmp);
        lista[tmp-1]++;
    }
    printf("%lld",analizar(0,0));
    return 0;
}

long long int analizar(long long int divisiones, long long int posicion){
    long long int resultado = 0;
    long long int i;

    float mayor = pow(2,(n-divisiones))*posicion + pow(2,(n-divisiones));
    float menor = pow(2,(n-divisiones))*posicion;

    for (i = menor; i < mayor; i++){
        resultado += lista[i];
    }

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