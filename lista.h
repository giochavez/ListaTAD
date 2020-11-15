#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"



struct lista {
    int tam;
    Nodo *inicio;
    Nodo *fin;
};

typedef struct lista Lista;

void iniciarLista(Lista *pLista,int tam);
int vacia(Lista *pLista);
void agregarNodoFinal(Lista *pLista,void *pInfo);
void agregarNodoInicio(Lista *pLista,void *pInfo);
void recorre(Lista *pLista, void (operacion) (void *informacion) );
void *retiraNodoInicio(Lista *pLista);
void *retiraNodoFinal(Lista *pLista);
void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) );
void *retirarNodoFinal(Lista *pLista,void *clave, int (igualdad) (void *d1,void *d2) );
void *retirarElPrimerValor(Lista *pLista,void *pInfo, int (igualdad) (void *d1,void *d2) );
int agregarNodoAntesDe(Lista *pLista, void *clave, void *antes, int (igualdad)(void *d1, void *d2));

#endif // LISTA_H_INCLUDED
