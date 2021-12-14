#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    long long int pruebas,i,j;
    scanf("%lld",&pruebas);
    long long int p1,p2;
    char x1[10],x2[10];


    for ( j = 0; j < pruebas; j++){
        
        scanf("%s",x1);
        scanf("%lld",&p1);
        scanf("%s",x2);
        scanf("%lld",&p2);

        if (strlen(x1)+p1 > strlen(x2)+p2){
            printf("> ");
        }else if (strlen(x1)+p1 < strlen(x2)+p2){
            printf("< ");
        }else{
            int comparacion = 0;
            for (i = strlen(x1); i < 10; i++){
                x1[i] = '0';
            }
            for (i = strlen(x2); i < 10; i++){
                x2[i] = '0';
            }

            for (i = 0; i < 10; i++){
                if (x1[i] < x2[i] && comparacion == 0){
                    comparacion = 1;
                }else if (x1[i] > x2[i] && comparacion == 0){
                    comparacion = 2;
                }
            }
            
            if (comparacion == 0){
                printf("= ");
            }else if(comparacion == 1){
                printf("< ");
            }else{
                printf("> ");
            }
        }
        

    }
    
    return 0;
}
