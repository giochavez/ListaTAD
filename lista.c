#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void iniciarLista(Lista *pLista, int tam) {
    pLista->tam = tam;
    pLista->inicio = NULL;
    pLista->fin = NULL;
}

int vacia(Lista *pLista) {
    if (pLista->inicio == NULL) {
        return 1;
    }
    return 0;
}

void agregarNodoFinal(Lista *pLista,void *pInfo) {
     Nodo *pNodo;

     pNodo = crearNodo(pLista->tam,pInfo);
     if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
     }
     pLista->fin->siguiente = pNodo;
     pLista->fin = pNodo;
}

void agregarNodoInicio(Lista *pLista,void *pInfo) {
    Nodo *pNodo;
    pNodo = crearNodo(pLista->tam,pInfo);
    if (vacia(pLista)==1) {
        pLista->inicio = pNodo;
        pLista->fin = pNodo;
        return;
    }
    pNodo->siguiente = pLista->inicio;
    pLista->inicio = pNodo;

}

void recorre(Lista *pLista, void (operacion) (void *informacion) ) {
    Nodo *pNodo;

    if (vacia(pLista)==1) {
        printf("Lista vacia!\n");
        return;
    }
    pNodo = pLista->inicio;
    while (pNodo != NULL) {
        operacion(pNodo->informacion);
        pNodo = pNodo->siguiente;
    }

}

void *retiraNodoInicio(Lista *pLista) {
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    res = pLista->inicio->informacion;
    q = pLista->inicio;
    pLista->inicio = q->siguiente;
    free(q); q=NULL;
    return res;
}

void *retiraNodoFinal(Lista *pLista) {
    void *res;
    Nodo *q;
    if (vacia(pLista)) {
        return NULL;
    }
    if (pLista->inicio==pLista->fin) {
        res = pLista->inicio->informacion;
        free(pLista->inicio);
        pLista->inicio=pLista->fin=NULL;
        return res;
    }
    q = pLista->inicio;
    while (q->siguiente!=pLista->fin) {
        q = q->siguiente;
    }
    res = pLista->fin->informacion;
    free(pLista->fin);
    q->siguiente = NULL;
    pLista->fin = q;
    return res;
}

void *buscarElPrimerValor(Lista *pLista,void *valor, int (igualdad) (void *d1,void *d2) ){
    Nodo *pNodo;

    pNodo = pLista->inicio;
    while(pNodo != NULL){
        if(igualdad(valor, pNodo->informacion)==1)
            return pNodo->informacion;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}
void *retirarElPrimerValor(Lista *pLista,void *pInfo, int (igualdad) (void *d1,void *d2) ){
    Nodo *pNodo;
    Nodo *pAnterior;
    void *res;
    if(vacia(pLista))
        return NULL;
    if(igualdad(pLista->inicio->informacion, pInfo))
        return retiraNodoInicio(pLista);
    if(igualdad(pLista->fin->informacion, pInfo))
        return retiraNodoFinal(pLista);
        pAnterior = pLista->inicio;
        pNodo = pLista->inicio->siguiente;
    while(pNodo != pLista->fin){
        if(igualdad(pNodo->informacion, pInfo)==1){
            pAnterior->siguiente = pNodo->siguiente;
            res = pNodo->informacion;
            free(pNodo);
            return res;
        }
        pAnterior = pNodo;
        pNodo = pNodo->siguiente;
    }
    return NULL;
}

int agregarNodoAntesDe(Lista *pLista,void *clave, void *antes, int (igualdad) (void *d1,void *d2)) {
    Nodo *pNodo;
    Nodo *pAnterior;
	if (vacia(pLista)) {
        return 0;
    }
	if(igualdad(pLista->inicio->informacion, antes)==1){
		agregarNodoInicio(pLista, clave);
		return 1;
}
 	pAnterior = pLista->inicio;
	pNodo = pLista->inicio->siguiente;
		while(pNodo!=NULL){
		if(igualdad(pNodo->informacion, antes)==1){
			pAnterior->siguiente = crearNodo(pLista->tam, clave);
			pAnterior->siguiente->siguiente = pNodo;
			return 1;
		}
		pAnterior = pNodo;
		pNodo = pNodo->siguiente;
}
	return 0;
}







