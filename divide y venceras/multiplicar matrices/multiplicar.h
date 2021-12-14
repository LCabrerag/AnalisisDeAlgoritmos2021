///////////////////////////////
//          INCLUDES         //
///////////////////////////////
#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////
//          TIPOS DE DATOS         //
/////////////////////////////////////

/*Tipo de dato correspondiente a la matriz cuadrada, tiene los siguientes valores
matriz: un arreglo bidimensional que almacena los valores de la matriz
renglones: un entero que almacena el tamaño de la matriz
*/
typedef struct{
    int** matriz;
    int renglones;
} matriz;


////////////////////////////////
//          FUNCIONES         //
////////////////////////////////

/*Inicializa la variable tipo "matriz", se les asigna memoria a la variable, se coloca el valor 0 a la matriz y el valor de n para "renglones"*/
int init_matriz(matriz*, int);

/*Multiplica dos matrices*/
int mult_matr(matriz*, matriz*, matriz*);

/*Asigna valores aleatorios a la matriz destino*/
int asig_RDM(matriz*);

/*Multiplica la matriz A y B con el algoritmo de strassen, el resultado es colocado en C*/
int strassen_matriz(matriz* , matriz*, matriz*);

/*Suma la matriz A y B, el resultado es colocado en C
regresa 1 si la suma se realizó con exito y 0 cuando las matrices tienen dimensiones diferentes
y no se puede realizar la suma*/
int sumar_matr(matriz*, matriz*, matriz*);

/*Resta la matriz B a A, el resultado es colocado en C
regresa 1 si la resta se realizó con exito y 0 cuando las matrices tienen dimensiones diferentes
y no se puede realizar la resta*/
int restar_matr(matriz*, matriz*, matriz*);

/*imprime la matriz "mat"*/
void print_mat(matriz*);