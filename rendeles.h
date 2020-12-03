#ifndef RENDELES_H
#define RENDELES_H

#include <stdlib.h>

#include "etel.h"

static unsigned int LEGNAGYOBB_ID=0;

typedef struct Rendeles {
    unsigned int id;
    unsigned int asztal_id;
    unsigned int vegosszeg;
    struct EtelekListaja *etelek;
} Rendeles;

typedef struct EtelekListaja{
    struct Etel *etel;
    struct EtelekListaja *kovetkezo;
}EtelekListaja;


void rendelesKiirasKonzolra(const Rendeles rend){
    printf("%d id %d asztal %d tetelek %d vegosszeg \n", rend.id, rend.asztal_id, rend.vegosszeg);
}



int hozzaadasEtelekhez(struct EtelekListaja **kezd, struct Etel *ujEtel){
    struct EtelekListaja* ujLista = (struct EtelekListaja*) malloc(sizeof(struct EtelekListaja));
    ujLista->etel=ujEtel;
    ujLista->kovetkezo=*kezd;
    *kezd=ujLista;

    return 0;

}

int rendelesVegosszege(const struct EtelekListaja *lista){
    int vege=0;
    while (lista!=NULL){
        vege+=lista->etel->ar;
        lista=lista->kovetkezo;

    }
    printf("VEGE %d\n",vege);
    return vege;
}

void etelekListajanakKiirasaKonzolra(const struct EtelekListaja* lista){
    while (lista!=NULL){
        etelKiirasKonzolra(*lista->etel);
        lista=lista->kovetkezo;
    }
}

#endif