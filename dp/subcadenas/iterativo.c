#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc == 3){
        int i;
        int j;
        int m = strlen(argv[1]);
        int n = strlen(argv[2]);
        char* x = argv[1];
        char* y = argv[2];
        int c[m+1][n+1];
        for (i = 0; i < m+1; i++){
            c[i][0] = 0;
        }
        for (j = 0; j < n+1; j++){
            c[0][j] = 0;
        }
        for (i = 1; i < m+1; i++){
            for ( j = 1; j < n+1; j++){
                if (x[i-1] == y[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                }else if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                }else{
                    c[i][j] = c[i][j-1];
                }
            }
        }
        
        
        printf("%d \n",c[m][n]);
        
    }
    
    return 0;
}
