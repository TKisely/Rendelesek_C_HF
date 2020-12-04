#include <stdlib.h>
#include <stdio.h>

#include "rendeles.h"

#include "rendeles_lista.h"


void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles){
   struct Rendeles_Lista* ujLista=(struct Rendeles_Lista*) malloc(sizeof(struct Rendeles_Lista));
   ujLista->rendeles=ujRendeles;
   ujLista->kovetkezo=*kezd;
   *kezd=ujLista;
}

void rendelesek_listazasa(const struct Rendeles_Lista *lista){
    while (lista!=NULL){
        printf("\nRENDELEST TALALTAM\n");
        printf("\n talalt id: %d\n",lista->rendeles->id);
        printf("\n a hozza tartozo asztal: \t %d \n",lista->rendeles->asztal_id);
        lista=lista->kovetkezo;

    }

}

Rendeles rendeles_asztal_id_alapjan(const struct Rendeles_Lista *lista, unsigned int asztal_id){
    Rendeles rend;
    while (lista!=NULL){
        if (lista->rendeles->asztal_id==asztal_id){
            printf("\nMEGTALALTAM\n");
            rend=*lista->rendeles;
            return rend;
        }
        lista=lista->kovetkezo;
    }

    printf("\nNEM TALALOM\n");

}

unsigned int get_legnagyobb_id(){
    return LEGNAGYOBB_ID;
}

void legnagyobb_id_novelese(){
    LEGNAGYOBB_ID++;
}