#ifndef RENDELES_LISTA_H
#define RENDELES_LISTA_H

typedef struct Rendeles_Lista {
    struct Rendeles *rendeles;
    struct Rendeles_Lista *kovetkezo;
} Rendeles_Lista;

static unsigned int LEGNAGYOBB_ID=0;

void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles);
void rendelesek_listazasa(const struct Rendeles_Lista *lista);
unsigned int get_legnagyobb_id();
void legnagyobb_id_novelese();

#endif //RENDELES_LISTA_H
