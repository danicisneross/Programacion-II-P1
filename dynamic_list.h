/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniela A Cisneros Sande LOGIN 1: d.cisneross
 * AUTHOR 2: Candela Iglesias Lorenzo LOGIN 2: candela.iglesias
 * GROUP: 4.1
 * DATE: 24/ 02 / 22
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL NULL

typedef struct tNode *tPosL;
struct tNode {
    tItemL data;
    tPosL next;
};
typedef tPosL tList;

void createEmptyList(tList *L);

/*
 * OBJETIVO: crear una lista vacia.
 * ENTRADA: -tList: lista.
 * SALIDA: una lista vacia.
 * POSTCD: la lista queda inicializada y no contine elementos.
*/

bool isEmptyList(tList L);

/*
 * OBJETIVO: determina si la lista vacia.
 * ENTRADA: -tList: lista de productos.
 * SALIDA: un valor de tipo bool donde aparece:
 *              Verdadero: si esta vacia.
 *              Falso: en caso contrario.
*/

tPosL first(tList L);

/*
 * OBJETIVO: devuelve la posición del primer elemento de la lista.
 * ENTRADA: -tList: lista de productos.
 * SALIDA: la primera posicion de la lista.
 * PRECD: la lista no está vacía..
*/

tPosL last(tList L);

/*
 * OBJETIVO: devuelve la posición del último elemento de la lista.
 * ENTRADA: -tList: lista de productos.
 * SALIDA: la ultima posicion de la lista.
 * PRECD: la lista no está vacía.
*/

tPosL next(tPosL p, tList L);

/*
 * OBJETIVO: devuelve la posición en la lista del elemento siguiente al de la posición indicada
 *           (o LNULL si la posición no tiene siguiente).
 * ENTRADA: -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: la posicion siguiente a la indicada.
 * PRECD: la posición indicada es una posición válida en la lista.
*/

tPosL previous(tPosL p, tList L);

/*
 * OBJETIVO: devuelve la posición en la lista del elemento anterior al de la posición indicada
 *           (o LNULL si la posición no tiene anterior).
 * ENTRADA: -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: la posicion anterior a la indicada.
 * PRECD: la posición indicada es una posición válida en la lista.
*/

bool createNode(tPosL *p);

/*
 * OBJETIVO: inicializa un nodo reservando espacio en la memoria.
 * ENTRADA: -tPosL: posicion de un elemento de la lista.
 * SALIDA: un valor de tipo bool donde aparece:
 *              Verdadero: si el nodo no es NULL.
 *              Falso: en caso contrario.
 * POSTCD: el nodo reserva su respectivo espacio en la memoria.
*/

bool insertItem(tItemL d, tPosL p, tList *L);

/*
 * OBJETIVO: inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL,
             entonces se añade al final.
 * ENTRADA: -tItemL: cojunto de datos de un producto de la lista.
 *          -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: un valor de tipo bool donde aparece:
 *              Verdadero: si el elemento fue insertado.
 *              Falso: en caso contrario.
 * PRECD: la posición indicada es una posición válida en la lista o bien nula (LNULL).
 * POSTCD: las posiciones de los elementos de la lista posteriores a la del
           elemento insertado pueden haber variado.
*/

void deleteAtPosition(tPosL p, tList *L);

/*
 * OBJETIVO: elimina de la lista el elemento que ocupa la posición indicada.
 * ENTRADA: -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: la lista sin dicha posicion (borrado el elemento que contenia).
 * PRECD: la posición indicada es una posición válida en la lista.
 * POSTCD: las posiciones de los elementos de la lista posteriores a la
           posicion eliminada pueden haber variado.
*/

tItemL getItem(tPosL p, tList L);

/*
 * OBJETIVO: devuelve el contenido del elemento de la lista que ocupa la posición indicada.
 * ENTRADA: -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: el contenido del elemento de dicha posicion.
 * PRECD: la posición indicada es una posición válida en la lista.
*/

void updateItem(tItemL d, tPosL p, tList *L);

/*
 * OBJETIVO: modifica el contenido del elemento situado en la posición indicada.
 * ENTRADA: -tItemL: cojunto de datos de un producto de la lista.
 *          -tPosL: posicion de un elemento de la lista.
 *          -tList: lista de productos.
 * SALIDA: la lista con el contenido de dicha posicion actualizado.
 * PRECD: la posición indicada es una posición válida en la lista.
 * POSTCD: el orden de los elementos de la lista no se ve modificado.
*/

tPosL findItem(tProductId pd, tList L);

/*
 * OBJETIVO: devuelve la posición del primer elemento de la lista cuyo identificador de
             producto se corresponda con el indicado (o LNULL si no existe tal elemento).
 * ENTRADA:  -tProductId:  identificador de un producto.
 *           -tList: lista de productos.
 * SALIDA: posicion del producto indicado.
*/

#endif