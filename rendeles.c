#include <stdlib.h>
#include <stdio.h>
#include "etel.h"

#include "rendeles.h"
#include "fajlkezeles.h"




void rendelesKiirasKonzolra(const Rendeles rend){
    printf("%d id %d asztal %d tetelek %d vegosszeg \n", rend.id, rend.asztal_id);
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
        etlaprolIDAlapjanKiiras(lista->etel->id);
        lista=lista->kovetkezo;
    }
}
