#include <stdio.h>
#include <stdlib.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(int argc, char const *argv[]){
    if (argc == 4){
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        int c = atoi(argv[3]);
        int resultado = c*2;
        if (a == b){
            resultado += a*2;
        }else{
            resultado += MIN(a,b)*2 +1;
        }
        printf("%d \n",resultado);
    }
    return 0;
}
