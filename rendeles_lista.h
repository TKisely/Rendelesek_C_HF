#ifndef RENDELES_LISTA_H
#define RENDELES_LISTA_H

typedef struct Rendeles_Lista {
    struct Rendeles *rendeles;
    struct Rendeles_Lista *kovetkezo;
} Rendeles_Lista;


void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles);
void rendelesek_listazasa(const struct Rendeles_Lista *lista);

#endif //RENDELES_LISTA_H
