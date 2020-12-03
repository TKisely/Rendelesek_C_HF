#ifndef RENDELES_LISTA_H
#define RENDELES_LISTA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Rendeles_Lista {
    struct Rendeles *rendeles;
    struct Rendeles_Lista *kovetkezo;
} Rendeles_Lista;

void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles);
void rendelesek_listazasa();

#endif //RENDELES_LISTA_H
