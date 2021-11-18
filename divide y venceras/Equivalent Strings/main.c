#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int iguales(char* string1,char* string2);
int equivalente(char* string1,char* string2);

int main(int argc, char *argv[]){
    if (argc == 3){
        if (equivalente(argv[1],argv[2])){
            printf("SI\n");
        }else{
            printf("NO\n");
        }
        
    }
    
    return 0;
}

int iguales(char* string1,char* string2){
    return (strcmp(string1,string2) == 0)?1:0;
}


int equivalente(char* string1,char* string2){
    if (strcmp(string1,string2) == 0){
        return 1;
    }else if(strlen(string1) == strlen(string2) && strlen(string2)%2 == 0){
        char* a1,*b1,*a2,*b2;
        int i;
        a1 = (char*) calloc(strlen(string1)/2,sizeof(char));
        a2 = (char*) calloc(strlen(string1)/2,sizeof(char));
        b1 = (char*) calloc(strlen(string1)/2,sizeof(char));
        b2 = (char*) calloc(strlen(string1)/2,sizeof(char));
        for (i = 0; i < strlen(string1)/2; i++){
            a1[i] = string1[i];
            a2[i] = string1[i+strlen(string1)/2];
            b1[i] = string2[i];
            b2[i] = string2[i+strlen(string1)/2];     
        }
        
        return (equivalente(a1,b1) && equivalente(a2,b2)) || (equivalente(a1,b2) && equivalente(a2,b1));
        
    }else{
        return 0;
    }
    
}