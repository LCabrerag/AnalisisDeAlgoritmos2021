#include <stdio.h>
#include <stdlib.h>

long long int encuentra_k(long long int* lista,long long int n, long long h);
void ordenar(long long int** lista, long long int tamano);

int main(int argc, char const *argv[]){
    long long int pruebas,tmp,i,n,*lista,j,h;
    scanf("%lld",&pruebas);
    for (i = 0; i < pruebas; i++){
        scanf("%lld",&n);
        scanf("%lld",&h);
        lista = (long long int*) calloc(n,sizeof(long long int));
        for (j = 0; j < n; j++){
            scanf("%lld",&tmp);
            lista[j] = tmp;
        }
        ordenar(&lista,n);
        printf("%lld ",encuentra_k(lista,n,h));
    }
    
    return 0;
}

long long int encuentra_k(long long int* lista,long long int n, long long h){
    if (h > n){
        int* diferencias = calloc(n-1,sizeof(int));
        long long int i,j;
        long long int division = (h/n + (h%n > 0?1:0));
        long long int naux = n;

        for (i = 0; i < n-1; i++){
            diferencias[i] = lista[i+1] - lista[i];
        }
        
        for (i = 0; i < n-1; i++){
            if (diferencias[i] < division && diferencias[i] > 0){
                h -= diferencias[i];
                naux--;
                division = (h/naux + (h%naux > 0?1:0));
                diferencias[i] = 0;
                i = 0;
            }
            
        }
        return division;
        
    }else{
        return 1;
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

//n golpes
//h vida
//a n pocision golpes


/**
 for (i = 0; i < n-1; i++){
            if (lista[i+1]-lista[i] < division && lista[i] != 0){
                
                h -= lista[i+1]-lista[i];
                ncal--;
                printf("vvvvv   %lld %lld %lld %lld %lld\n",ncal,h,division,lista[i],lista[1+i]);
                lista[i] = 0;
                i=0;
                division = (h/ncal + (h%ncal > 0?1:0));
            }
        }



*/