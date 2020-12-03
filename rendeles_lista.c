#include "rendeles_lista.h"


void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles){
   struct Rendeles_Lista* ujLista=(struct Rendeles_Lista*) malloc(sizeof(struct Rendeles_Lista));
   ujLista->rendeles=ujRendeles;
   ujLista->kovetkezo=*kezd;
   *kezd=ujLista;
}

void rendelesek_listazasa(const struct Rendeles_Lista *lista){
    while (lista!=NULL){
        lista=lista->kovetkezo;
        printf("\nRENDELEST TALALTAM\n");
    }

}