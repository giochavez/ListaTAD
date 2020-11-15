#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void imprimirEntero(void *dato) {
    int *x;
    x = (int *)dato;
    printf("%d\n",*x);
}

//regresa un valor igual a 1 si son iguales
//regresa un valor igual a 0 si no son iguales

int comparaEntero(void *dato1, void *dato2) {
    int *x, *y;
    x = (int *)dato1;
    y = (int *)dato2;
    if(*x==*y)
        return 1;
    return 0;
}

void imprimirReal(void *dato) {
    double *x;
    x = (double *)dato;
    printf("%0.2f\n",*x);
}

int comparaReal(void *dato1, void *dato2) {
    double *x, *y;
    x = (double *)dato1;
    y = (double *)dato2;
    if(abs(*x-*y) < 1E-7)
        return 1;
    return 0;
}

int main()
{
    int k, j, z, *pEntero;
    double v;
    Lista miListaEnteros;
    Lista otraListaReal;

    iniciarLista(&miListaEnteros,sizeof(int));
    iniciarLista(&otraListaReal,sizeof(double));


    for (k=10;k<50;k+=5) {
        agregarNodoFinal(&miListaEnteros,&k);
        v = k*0.555;
        agregarNodoFinal(&otraListaReal,&v);
    }
    printf("Listas iniciales: \n");
    recorre(&miListaEnteros, imprimirEntero);
    printf("\n");
    recorre(&otraListaReal, imprimirReal);
    printf("\n");

    printf("Lista modificada\n");
    pEntero  = (int *)retiraNodoFinal(&miListaEnteros);
    recorre(&miListaEnteros, imprimirEntero);
    printf("N%cmero retirado: %d\n",163, *pEntero);
    printf("\n");

    printf("Lista modificada\n");
    pEntero  =  (int *)retiraNodoFinal(&miListaEnteros);
    recorre(&miListaEnteros, imprimirEntero);
    printf("N%cmero retirado: %d\n", 163, *pEntero);
    printf("\n");

    printf("Lista modificada:\n\n");
    k = 1000;
    agregarNodoInicio(&miListaEnteros,&k);
    recorre(&miListaEnteros, imprimirEntero);
    printf("\n");

    k=25;
    pEntero = buscarElPrimerValor(&miListaEnteros, &k, comparaEntero);
    if (pEntero != NULL){
        *pEntero += 1;
        printf("S%c existe!\n", 161);
    }
    else
        printf("No existe");
        recorre(&miListaEnteros, imprimirEntero);
        printf("\n");
        k=30;
        printf("Se retir%c el n%cmero %d:\n", 162, 163, k);
        retirarElPrimerValor(&miListaEnteros, &k, comparaEntero);
        recorre(&miListaEnteros, imprimirEntero);


        k= 82;
        j= 35;
        z = agregarNodoAntesDe(&miListaEnteros,&k,&j,comparaEntero);
        if(z == 1){
            printf("\nSe agreg%c el n%cmero %d:\n",162, 163, k);
        }
        else{
            printf("No se pudo agregar el n%cmero %d:\n", 163, k);
        }
        recorre(&miListaEnteros, imprimirEntero);
        printf("\n");
        printf("\n");
        /*
        if (buscar(&miListaEnteros,&k,comparaEntero)!=NULL)
            printf("S%c existe!\n", 161);
        else
            printf("No existe el n%cmero", 163);
        */
    return 0;
}

