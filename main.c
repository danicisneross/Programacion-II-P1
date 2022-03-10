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
        prod.bidCounter = 0;

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
            printf("+ Error: New not possible");
        }
    } else {
        printf("+ Error: New not possible");
    }
}

void delete(tProductId prodId, tList *L){
    tPosL p;
    tItemL prod;
    char category[N];
    p = findItem(prodId, *L);

    if (prod.productCategory == book) {
        strcpy(category, "book");
    } else {
        strcpy(category, "painting");
    }

    if(p != LNULL) {
        prod = getItem(p, *L);
        deleteAtPosition(p, L);
        printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", prodId, prod.seller,category, prod.productPrice, prod.bidCounter);
    } else {
        printf("+ Error: Delete not possible");
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {

    printf("********************\n");
    tProductCategory category;
    switch (command) {
        case 'N':
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            if(strcmp(param3, "book") == 0) {
                category = book;
            } else {
                category = painting;
            }
            new(param1, param2, category, atof(param4), L);

            break;
        case 'S':
            break;
        case 'B':
            break;
        case 'D':
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
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

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
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






