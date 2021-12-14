#include <stdio.h>

typedef struct {
    int x;
    int y;
} coordenada;

coordenada analizar(coordenada B);

int main(int argc, char const *argv[]){
    int casos,i;
    coordenada B,C;
    scanf("%d",&casos);
    for ( i = 0; i < casos; i++){
        scanf("%d",&(B.x));
        scanf("%d",&(B.y));
        C = analizar(B);
        printf("%d %d ",C.x,C.y);
    }
    
    return 0;
}

coordenada analizar(coordenada B){
    coordenada C;
    int i;
    if ((B.x + B.y)%2 == 0){
        C = B;
        for (i = 0; i < (B.x + B.y)/2; i++){
            if (C.x != 0){
                C.x--;
            }else{
                C.y--;
            }            
        }
    }else{
        C.x = -1;
        C.y = -1;
    }
    
    return C;   
}