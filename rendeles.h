

#ifndef RENDELES_H
#define RENDELES_H


typedef struct Rendeles {
    unsigned int id;
    unsigned int asztal_id;
    struct EtelekListaja *etelek;
} Rendeles;

typedef struct EtelekListaja{
    struct Etel *etel;
    struct EtelekListaja *kovetkezo;
}EtelekListaja;


void rendelesKiirasKonzolra(const Rendeles rend);

int hozzaadasEtelekhez(struct EtelekListaja **kezd, struct Etel *ujEtel);

int rendelesVegosszege(const struct EtelekListaja *lista);

void etelekListajanakKiirasaKonzolra(const struct EtelekListaja* lista);

#endif