#include <stdio.h>
#include <string.h>

#define VOCAL(X) (((X) == 'a' || (X) == 'e' || (X) == 'i' || (X) == 'o' || (X) == 'u' ) ? (1) : (0)) 


int main(int argc, char const *argv[]){
    char s[1001];
    char t[1001];
    int i,cumple = 1;

    scanf("%s",s);
    scanf("%s",t);

    if (strlen(s) == strlen(t)){
        for ( i = 0; i < strlen(t); i++){
            if (VOCAL(s[i]) != VOCAL(t[i])){
                cumple = 0;
            }
        }
        if (cumple){
            printf("YES");
        }else{
            printf("NO");
        }
    }else{
        printf("NO");
    }
    
    

    return 0;
}