#include "multiplicar.h"

int main(){
    matriz A;
    matriz B;
    matriz C;
    int n;

    printf("Ingresa el tamaño de las matrices:\n");
    scanf("%d", &n);

    init_matriz(&A,n);
    init_matriz(&B,n);
    init_matriz(&C,n);

    asig_RDM(&A);
    asig_RDM(&B);

    strassen_matriz(&A, &B, &C);

    print_mat(&A);
    print_mat(&B);
    print_mat(&C);
}

int asig_RDM(matriz* destino){
    int i,j;
    for (i = 0; i < destino->renglones; i++){
        for (j = 0; j < destino->renglones; j++){
            destino->matriz[i][j] = rand()%10 + 1;
        }
    }
}

int init_matriz(matriz* destino, int n){
    int i,j;
    destino->renglones = n;
    destino->matriz = calloc(sizeof(int*) ,n);

    for (i = 0; i < n; i++){
        destino->matriz[i] = calloc(sizeof(int) ,n);
        for (j = 0; j < n; j++){
            destino->matriz[i][j] = 0;
        }
    }

    return 1;
}

int strassen_matriz(matriz* A, matriz* B, matriz* C){ 
  
    int i,j,n = A->renglones/2;

    matriz S[10];
    matriz A11, A12, A21, A22;
    matriz B11, B12, B21, B22;
    matriz C11, C12, C21, C22;


    init_matriz(&A11, A->renglones/2);
    init_matriz(&A12, A->renglones/2);
    init_matriz(&A21, A->renglones/2);
    init_matriz(&A22, A->renglones/2);

    init_matriz(&B11, B->renglones/2);
    init_matriz(&B12, B->renglones/2);
    init_matriz(&B21, B->renglones/2);
    init_matriz(&B22, B->renglones/2);

    init_matriz(&C11, C->renglones/2);
    init_matriz(&C12, C->renglones/2);
    init_matriz(&C21, C->renglones/2);
    init_matriz(&C22, C->renglones/2);

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            A11.matriz[i][j] = A->matriz[i][j];
            A12.matriz[i][j] = A->matriz[i][j+n];
            A21.matriz[i][j] = A->matriz[i+n][j];
            A22.matriz[i][j] = A->matriz[i+n][j+n];
            B11.matriz[i][j] = B->matriz[i][j];
            B12.matriz[i][j] = B->matriz[i][j+n];
            B21.matriz[i][j] = B->matriz[i+n][j];
            B22.matriz[i][j] = B->matriz[i+n][j+n];
        }
    }

    for (i = 0; i < 10; i++)
            init_matriz(&S[i],n);

    restar_matr(&B12, &B22,&S[0]);
    sumar_matr(&A11, &A12, &S[1]);
    sumar_matr(&A21, &A22,&S[2]);
    restar_matr(&B21, &B11, &S[3]);
    sumar_matr(&A11, &A22,&S[4]);
    sumar_matr(&B11, &B22, &S[5]);
    restar_matr(&A12, &A22, &S[6]);
    sumar_matr(&B21, &B22, &S[7]);
    restar_matr(&A11, &A21, &S[8]);
    sumar_matr(&B11, &B12, &S[9]);

    if (n == 1){
        int P[7];

        P[0] = A11.matriz[0][0]*S[0].matriz[0][0];
        P[1] = S[1].matriz[0][0]*B22.matriz[0][0];
        P[2] = S[2].matriz[0][0]*B11.matriz[0][0];
        P[3] = S[3].matriz[0][0]*A22.matriz[0][0];
        P[4] = S[4].matriz[0][0]*S[5].matriz[0][0];
        P[5] = S[6].matriz[0][0]*S[7].matriz[0][0];
        P[6] = S[8].matriz[0][0]*S[9].matriz[0][0];

        C11.matriz[0][0] = P[4] + P[3] - P[1] + P[5];
        C12.matriz[0][0] = P[0] + P[1];
        C21.matriz[0][0] = P[2] + P[3];
        C22.matriz[0][0] = P[4] + P[0] - P[2] - P[6];
    }else{
        
        matriz P[7];
        for (i = 0; i < 7; i++)
            init_matriz(&P[i],n);

        strassen_matriz(&A11,&S[0],&P[0]);
        strassen_matriz(&S[1],&B22,&P[1]);
        strassen_matriz(&S[2],&B11,&P[2]);
        strassen_matriz(&A22,&S[3],&P[3]);
        strassen_matriz(&S[4],&S[5],&P[4]);
        strassen_matriz(&S[6],&S[7],&P[5]);
        strassen_matriz(&S[8],&S[9],&P[6]);

        sumar_matr(&P[4], &P[3],&C11);
        restar_matr(&C11, &P[1],&C11);
        sumar_matr(&C11, &P[5],&C11); 
        
        sumar_matr(&P[0], &P[1],&C12);
        sumar_matr(&P[2], &P[3],&C21);

        sumar_matr(&P[4], &P[0],&C22);
        restar_matr(&C22, &P[2],&C22);
        restar_matr(&C22, &P[6],&C22);  
        
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            C->matriz[i][j] = C11.matriz[i][j];
            C->matriz[i][j+n] = C12.matriz[i][j];
            C->matriz[i+n][j] = C21.matriz[i][j];
            C->matriz[i+n][j+n] = C22.matriz[i][j];
        }
    }
    
}

void print_mat(matriz* mat){
    int i,j;
    printf("------------------------------------\n");
    for (i = 0; i < mat->renglones; i++){
        for (j = 0; j < mat->renglones; j++){
            printf("%d ",mat->matriz[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
    
}

int sumar_matr(matriz* A, matriz* B, matriz* C){
    if (A->renglones == B->renglones){
        if (C->renglones != A->renglones)
            init_matriz(C,A->renglones);
        
        int i,j;
        int n = A->renglones;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                C->matriz[i][j] = A->matriz[i][j] + B->matriz[i][j];
            }
        }
        return 1;    
    }else{
        return 0;
    }
}

int restar_matr(matriz* A, matriz* B, matriz* C){
    if (A->renglones == B->renglones){
        if (C->renglones != A->renglones)
            init_matriz(C,A->renglones);
        
        int i,j;
        int n = A->renglones;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                C->matriz[i][j] = A->matriz[i][j] - B->matriz[i][j];
            }
        }
        return 1;    
    }else{
        return 0;
    }
}

int mult_matr(matriz* A, matriz* B, matriz* C){
    int i,j,k;
    int n = A->renglones;
    C->renglones = n;
    C->matriz = calloc(sizeof(int*) ,n);

    for (i = 0; i < n; i++){
        C->matriz[i] = calloc(sizeof(int) ,n);
    }
   
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            C->matriz[i][j] = 0;
            for (k = 0; k < n; k++){
                C->matriz[i][j] += A->matriz[i][k]*B->matriz[k][j];
            }
        }
    }
    
}