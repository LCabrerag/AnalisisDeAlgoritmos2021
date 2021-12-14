#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int i;
    int j;
}vector;

void analizar_vectores(vector* lista, int cantidad);

int main(int argc, char const *argv[]){
    if (argc == 2){
        int i,cantidad;
        vector* vectores;
        char buffer[255];
        FILE* input;
        input = fopen(argv[1],"r");
        
        fscanf(input,"%s",buffer);
        cantidad = atoi(buffer);
        vectores = (vector*) calloc(cantidad,sizeof(vector));

        for (i = 0; i < cantidad; i++){
            fscanf(input,"%s",buffer);
            vectores[i].i = atoi(buffer);
            fscanf(input,"%s",buffer);
            vectores[i].j = atoi(buffer);
        }

        fclose(input);
        analizar_vectores(vectores, cantidad);
    }
    return 0;
}


void analizar_vectores(vector* lista, int cantidad){
    
}

vector suma_vectores(vector a, vector b){
    vector salida;
    salida.i = a.i + b.i;
    salida.j = a.j + b.j;
    return salida;
}

int absoluto_vector(vector a){
    return sqrt(a.i*a.i + a.j*a.j);
}