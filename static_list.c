/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniela A Cisneros Sande LOGIN 1: d.cisneross
 * AUTHOR 2: Candela Iglesias Lorenzo LOGIN 2: candela.iglesias
 * GROUP: 4.1
 * DATE: 24/ 02 / 22
 */

#include "static_list.h"
#include "string.h"

void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}

bool isEmptyList(tList L) {
    return L.lastPos == LNULL;
}

tPosL first(tList L) {
    return 0;
}

tPosL last(tList L) {
    return L.lastPos;
}

tPosL next(tPosL p, tList L) {
    if (p == L.lastPos)
        return LNULL;
    else
        return ++p;
}

tPosL previous(tPosL p, tList L) {
    if (p == 0)
        return LNULL;
    else
        return --p;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;

    if (L->lastPos == MAX - 1) //La lista esta llena
        return false;
    else {
        L->lastPos++;
        if (p == LNULL) { //Insertar al final
            L->data[L->lastPos] = d;
        } else {
            for (i = L->lastPos; i >= p + 1; i--)
                L->data[i] = L->data[i - 1];
            L->data[p] = d;
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    L->lastPos--;
    for (i = p; i <= L->lastPos; i++)
        L->data[i] = L->data[i + 1];
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d;
}

tPosL findItem(tProductId pd, tList L) {
    tPosL p;

    if (L.lastPos == LNULL)
        return LNULL;
    else {
        for (p = first(L); p <= L.lastPos; p++) {
            if (strcmp(L.data[p].productId, pd) == 0)
                return p;
        }
        return LNULL;
    }
}
