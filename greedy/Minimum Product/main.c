#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long int mulpiplicacion_min(long int a, long int b, long int x, long int y, long int n);

int main(int argc, char const *argv[]){
    if (argc == 2){
        int i,pruebas;
        long int a, b, x, y, n,resultado;
        char buffer[255];
        FILE* input;
        input = fopen(argv[1],"r");
        
        fscanf(input,"%s",buffer);
        pruebas = atoi(buffer);

        for (i = 0; i < pruebas; i++){
            fscanf(input,"%s",buffer);
            a = atoi(buffer);
            fscanf(input,"%s",buffer);
            b = atoi(buffer);
            fscanf(input,"%s",buffer);
            x = atoi(buffer);
            fscanf(input,"%s",buffer);
            y = atoi(buffer);
            fscanf(input,"%s",buffer);
            n = atoi(buffer);
            
            resultado = mulpiplicacion_min(a, b, x, y, n);
            printf("%ld\n", resultado);
        }
        fclose(input);
    }
    
    return 0;
}


long int mulpiplicacion_min(long int a, long int b, long int x, long int y, long int n){
    long int i;
    long int resultado = LONG_MAX;
    if (n > (a-x+b-y)){
        n = (a-x+b-y);
    }
    
    for ( i = 0; i < n+1; i++){
        if ( resultado > ((a-i)*(b-n+i)) && (a-i)>=x && (b-n+i)>=y){
            //printf("%ld\n",i);
            resultado = ((a-i)*(b-n+i));
        }
        
    }
    return resultado;
}