//n - estudiantes
//m - puzzles en tienda
//f() - piezas en puzzle
//A - puzzle mas grande
//B - puzzle mas grande


//parametros n m
//          f(m)

#include <stdio.h>
#include <stdlib.h>

int ordenar(int** lista, int tamano);

int main(int argc, char const *argv[]){
    if (argc > 3){
        int n = atoi(argv[1]);
        int m = atoi(argv[2]);
        int* f = calloc(m,sizeof(int));
        int ab = -1;
        int i;
        for ( i = 0; i < m; i++){
            f[i] = atoi(argv[i+3]);
        }
        ordenar(&f,m);

        for (i = 0; i < m-n+1; i++){
            if (ab == -1 || f[i+m-n+1]-f[i] < ab){
                ab = f[i+m-n+1]-f[i];
            }
        }

        printf("%d\n",ab);
        
    }
    
    return 0;
}

int ordenar(int** lista, int tamano){
    int i,j;
    int tmp;
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