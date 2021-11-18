#include <stdio.h>
#include <string.h>

char* cadena1;
char* cadena2;

#define MAX(i,j) i > j ? i : j

int buscar(int, int);

int main(int argc, char *argv[]){
    if (argc == 3){
        int i = strlen(argv[1]);
        int j = strlen(argv[2]);
        cadena1 = argv[1];
        cadena2 = argv[2];
        printf("%d\n",buscar(i,j));
    }
    
    return 0;
}

int buscar(int i, int j){
    if (i == 0 || j == 0){
        return 0;
    }
    if (i > 0 && j > 0 && cadena1[i] == cadena2[j]){
        return buscar( i - 1,j-1 ) + 1;
    }
    if (i > 0 && j > 0 && cadena1[i] != cadena2[j]){
        MAX(buscar(i-1,j),buscar(i,j-1));
    }
}