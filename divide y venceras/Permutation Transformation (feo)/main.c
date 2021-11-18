#include <stdlib.h>
#include <stdio.h>

int transformacion(int* , int ,int);

int main(int argc, char *argv[]){
    if (argc > 1){
        int i;
        int* lista = (int*)calloc(argc -1,sizeof(int));
        for ( i = 0; i < argc-1; i++){
            lista[i] = atoi(argv[i+1]);
        }
        transformacion(lista,0,argc-1);
        printf("\n");
    }
    
    return 0;
}

int transformacion(int* lista, int altura,int longitud){
    int max = 0;
    int longitud_izq=0;
    int longitud_der=0;
    int* lista_izq= calloc(0, sizeof(int));
    int* lista_der= calloc(0, sizeof(int));
    int i,cambio=0;

    for (i = 0; i < longitud; i++){
        if (max<lista[i]){
            max = lista[i];
        }
    }

    for (i = 0; i < longitud; i++){
        if (max == lista[i]){
            cambio++;
        }else if(cambio == 0){
            longitud_izq++;
            lista_izq = (int*) realloc(lista_izq,sizeof(int)*longitud_izq);
            lista_izq[longitud_izq-1] =lista[i];
        }else{
            longitud_der++;
            lista_der = (int*) realloc(lista_der,sizeof(int)*longitud_der);
            lista_der[longitud_der-1] =lista[i];
        }
    }

    if (longitud_izq > 0){
        transformacion(lista_izq,altura+1,longitud_izq);
    }
    
    printf("%d ",altura);

    if (longitud_der > 0){
        transformacion(lista_der,altura+1,longitud_der);
    }

    
}