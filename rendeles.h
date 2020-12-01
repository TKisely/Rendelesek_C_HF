#ifndef RENDELES_H
#define RENDELES_H

#include "etel.h"

typedef struct Rendeles {
    unsigned int id;
    unsigned int asztal_id;
    unsigned int tetelek_szama;
    unsigned int vegosszeg;
    Etel* etelek;
} Rendeles;

void rendelesKiirasKonzolra(const Rendeles rend){
    printf("%d id %d asztal %d tetelek %d vegosszeg \n", rend.id, rend.asztal_id, rend.tetelek_szama, rend.vegosszeg);
}

#endif