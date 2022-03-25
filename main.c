/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniela A Cisneros Sande LOGIN 1: d.cisneross
 * AUTHOR 2: Candela Iglesias Lorenzo LOGIN 2: candela.iglesias
 * GROUP: 4.1
 * DATE: 24/ 02 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255
#define N 20

#ifdef DYNAMIC_LIST

#include "dynamic_list.h"

#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void new(tProductId pd, tUserId userId, tProductCategory prodCategory, tProductPrice price, tList *L) {
    char category[N];

    if (findItem(pd, *L) == LNULL) {
        tItemL prod;
        strcpy(prod.productId, pd);
        strcpy(prod.seller, userId);
        prod.bidCounter = 0;
        prod.productPrice = price;
        if (prodCategory == book) {
            prod.productCategory = book;
            strcpy(category, "book");
        } else {
            prod.productCategory = painting;
            strcpy(category, "painting");
        }
        if (insertItem(prod, LNULL, L) == true) {
            printf("* New: product %s seller %s category %s price %.2f \n", pd, userId, category, price);
        } else {
            printf("+ Error: New not possible\n");
        }
    } else if (findItem(pd, *L) != LNULL) {
        printf("+ Error: New not possible\n");
    }
}

/*
  *************************************** FUNCION NEW *********************************************

 * OBJETIVO: Alta de un nuevo producto con sus caracteristicas.
 * ENTRADA: -tProductId: Identificador del producto.
 *          -tUserId: Identificador del usuario.
 *          -tProductCategory: Categoria del producto (book, painting).
 *          -tProductPrice: Precio del producto.
 *          -tList: lista de productos.
 * SALIDA: La lista pasada por referencia con el nuevo usuario introducido.
 * PRECD: La lista debe estar creada y el producto no puede existir.
*/

void delete(tProductId prodId, tList *L) {
    tPosL p;
    tItemL prod;
    char category[N];
    p = findItem(prodId, *L);

    if (p != LNULL) {
        prod = getItem(p, *L);
        if (prod.productCategory == book) {
            prod.productCategory = book;
            strcpy(category, "book");
        } else {
            prod.productCategory = painting;
            strcpy(category, "painting");
        }
        deleteAtPosition(p, L);
        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", prodId, prod.seller, category,
               prod.productPrice, prod.bidCounter);
    } else {
        printf("+ Error: Delete not possible\n");
    }
}

/*
  ****************************** FUNCION DELETE **********************************

 * OBJETIVO: Baja un producto de la lista (todas sus caracteristicas se eliminaran).
 * ENTRADA: -tProductId: Identificador del producto.
 *          -tList: Lista de productos.
 * SALIDA: La lista pasada por referencia, sin el producto.
 * PRECD: La lista no debe estar vacia.
*/

void bid(tProductId prodId, tUserId userId, tProductPrice price, tList *L) {
    tItemL prod;
    tPosL p;
    p = findItem(prodId, *L);
    char category[N];

    if ((!isEmptyList(*L)) && (p != LNULL)) {
        prod = getItem(p, *L);
        if (prod.productCategory == book) {
            prod.productCategory = book;
            strcpy(category, "book");
        } else {
            prod.productCategory = painting;
            strcpy(category, "painting");
        }
        if ((price > prod.productPrice) && (strcmp(prod.seller, userId) != 0)) {
            prod.productPrice = price;
            prod.bidCounter++;
            updateItem(prod, p, L);
            printf("* Bid: product %s seller %s category %s price %.2f bids %d\n", prodId, prod.seller, category,
                   prod.productPrice, prod.bidCounter);
        } else {
            printf("+ Error: Bid not possible\n");
        }
    }
}

/*
  *************************************** FUNCION BID *********************************************

 * OBJETIVO: Puja por un determinado producto.
 * ENTRADA: -tProductId: Identificador del producto.
 *          -tUserId: Identificador del usuario.
 *          -tProductPrice: Precio del producto.
 *          -tList: Lista de productos.
 * SALIDA: La lista pasada por referencia con el precio de la puja actualizado.
 * PRECD: La lista debe existir y no puede estar vacia.
*/

void stats(tList *L) {
    tPosL p;
    tItemL prod;
    int books = 0, paintings = 0;  //contadores de categoria book y categoria painting, inicializadas a 0
    float priceBooks = 0, pricePaintings = 0; //acumuladores de los precios
    float averageBooks, averagePaintings;
    char category[N];

    if (!isEmptyList(*L)) {
        p = first(*L);
        while (p != LNULL) {
            prod = getItem(p, *L);
            if (prod.productCategory == book) {
                strcpy(category, "book");
                books++;
                priceBooks += prod.productPrice;
                printf("Product %s seller %s category %s price %.2f bids %d\n", prod.productId, prod.seller, category,
                       prod.productPrice, prod.bidCounter);
            } else if (prod.productCategory == painting) {
                strcpy(category, "painting");
                paintings++;
                pricePaintings += prod.productPrice;
                printf("Product %s seller %s category %s price %.2f bids %d\n", prod.productId, prod.seller, category,
                       prod.productPrice, prod.bidCounter);
            }
            p = next(p, *L);
        }
        if (books == 0) {
            averageBooks = 0;
        } else {
            averageBooks = (priceBooks / (float) books);
        }
        if (paintings == 0) {
            averagePaintings = 0;
        } else {
            averagePaintings = (pricePaintings / (float) paintings);
        }
        printf("\nCategory  Products    Price  Average\n"
               "Book      %8d %8.2f %8.2f\n"
               "Painting  %8d %8.2f %8.2f\n", books, priceBooks, averageBooks, paintings, pricePaintings,
               averagePaintings);
    } else {
        printf("+ Error: Stats not possible\n");
    }
}

/*
  *************************************** FUNCION STATS *******************************************

 * OBJETIVO: Mostrar el listado de productos actuales y sus datos.
 * ENTRADA: -tList: Lista de productos.
 * SALIDA: No hay parametros de salida (ni por referencia) ya que la lista no se modifica y solo se muestran sus datos.
 * PRECD: La lista no este vacia, de lo contrario los datos a mostrar estaran a cero.
*/

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {

    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3,
                   param4);
            if (strcmp(param3, "book") == 0) {
                new(param1, param2, book, atof(param4), L);
            } else if (strcmp(param3, "painting") == 0) {
                new(param1, param2, painting, atof(param4), L);
            }
            break;
        case 'S':
            printf("%s %c\n", commandNumber, command);
            stats(L);
            break;
        case 'B':
            printf("%s %c: product %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);
            bid(param1, param2, atof(param3), L);
            break;
        case 'D':
            printf("%s %c: product %s \n", commandNumber, command, param1);
            delete(param1, L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    tList L;
    createEmptyList(&L);

    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, &L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name);

    return 0;
}