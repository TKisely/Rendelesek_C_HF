#ifndef ETEL_H
#define ETEL_H

typedef struct Etel {
    unsigned int id;
    char nev[50];
    int ar;
} Etel;

void etelKiirasKonzolra(const Etel etel){
    printf("%d id %d ar \n",etel.id,etel.ar);
}

#endif