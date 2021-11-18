#include "main.h"

int main(int argc, char const *argv[]){
    
    int c_input;
    int* numeros;
    int c_numeros;
    int i,j;
    char buffer[255];
    FILE* input;
    input = fopen(argv[1],"r");
    
    if (argc == 2){
        fscanf(input,"%s",buffer);
        c_input = atoi(buffer);
        for (i = 0; i < c_input; i++){
            fscanf(input,"%s",buffer);
            c_numeros = atoi(buffer);
            numeros = (int*)calloc(c_numeros,sizeof(int));
            for (j = 0; j < c_numeros; j++){
                fscanf(input,"%s",buffer);
                numeros[j] = atoi(buffer);
            }
            acomodar(numeros, c_numeros,0);
            printf("\n");
        }
        fclose(input);
    }
    return 0;
}

int acomodar(int* lista,int tamano, int valor){
    //separamos
    int* izquierda;
    int* derecha;
    int i_tamano = 0;
    int d_tamano = 0;
    int i;
    int max = 0;
    int max_pos = 0;

    //buscamos el valor maximo
    for (i = 0; i < tamano; i++){
        if (max < lista[i]){
            max = lista[i];
            max_pos = i;
        }
    }

    //buscamos los valores de la izquierda
    i_tamano = max_pos;
    izquierda = (int*) calloc(i_tamano,sizeof(int));
    for (i = 0; i < i_tamano; i++){
        izquierda[i] = lista[i];
    }
    
    //buscamos los valores de la derecha
    d_tamano = tamano-max_pos-1;
    derecha = (int*) calloc(d_tamano,sizeof(int));
    for (i = 0; i < d_tamano; i++){
        derecha[i] = lista[max_pos+1+i];
    }

    //aplicamos recursividad con izquierda
    //con condicion para izquierda vacia

    if (i_tamano > 0){
        acomodar(izquierda,i_tamano,valor+1);
    }

    //imprimimos el valor maximo
    printf("%d ",valor);

    //continuamos con la recursividad del lado derecho
    if (d_tamano > 0){
        acomodar(derecha,d_tamano,valor+1);
    }
}