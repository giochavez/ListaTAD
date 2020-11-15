#include <stdlib.h>
#include <string.h>

#include "nodo.h"



Nodo *crearNodo(int tam, void *dirInfo) {
    Nodo *pNodo;
    pNodo = malloc(sizeof(Nodo));
    pNodo->informacion = malloc(tam);
    memcpy(pNodo->informacion,dirInfo,tam);
    pNodo->siguiente = NULL;
    return pNodo;
}
