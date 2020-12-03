#ifndef ETEL_H
#define ETEL_H

#include <stdio.h>

typedef struct Etel {
    unsigned int id;
    char nev[50];
    int ar;
} Etel;

void etelKiirasKonzolra(const Etel etel);

#endif