/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniela A Cisneros Sande LOGIN 1: d.cisneross
 * AUTHOR 2: Candela Iglesias Lorenzo LOGIN 2: candela.iglesias
 * GROUP: 4.1
 * DATE: 24/ 02 / 22
 */

#include "dynamic_list.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>

void createEmptyList(tList *L) {
    *L = LNULL;
}

bool isEmptyList(tList L) {
    return L == LNULL;
}

tPosL first(tList L) {
    return L;
}

tPosL last(tList L) {
    tPosL p;
    for (p = first(L); p->next != LNULL; p = p->next);
    return p;
}

tPosL next(tPosL p, tList L) {
    return p->next;
}

tPosL previous(tPosL p, tList L) {
    tPosL i;

    if (p == L) {
        return LNULL;
    } else {
        for (i = L; i->next != p; i = i->next);
        return i;
    }
}

bool createNode(tPosL *p) {
    *p = malloc(sizeof(**p));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i, j;
    if (!createNode(&i)) {
        return false;
    } else {
        i->data = d;
        i->next = LNULL;
        if (*L == LNULL) { //La lista esta vacia
            *L = i;
        } else if (p == LNULL) { // Ultima posicion
            for (j = *L; j->next != LNULL; j = j->next);
            j->next = i;
        } else if (p == *L) { //p es la primera posicion de la lista
            i->next = *L;
            *L = i;
        } else {
            i->data = p->data;
            p->data = d;
            i->next = p->next;
            p->next = i;
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList *L) {
    tPosL i;

    if (p == *L) {
        *L = (*L)->next;
    } else if (p->next == LNULL) {
        for (i = *L; i->next != p; i = i->next);
        i->next = LNULL;
    } else {
        i = p->next;
        p->data = i->data;
        p->next = i->next;
        p = i;
    }
    free(p);
}

tItemL getItem(tPosL p, tList L) {
    return p->data;
}

void updateItem(tItemL d, tPosL p, tList *L) {
    p->data = d;
}

tPosL findItem(tProductId pd, tList L) {
    tPosL p;

    for (p = L; p != LNULL; p = p->next) {
        if ((strcmp(p->data.productId, pd) == 0)) {
            return p;
        }
    }
    return LNULL;
}