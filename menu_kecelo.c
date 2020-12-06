#include <stdio.h>
#include <string.h>

#include "menu_nezetek.h"
#include "rendeles_lista.h"
#include "rendeles.h"
#include "etel.h"
#include "fajlkezeles.h"

#include "menu_kezelo.h"


void fomenu_kezelo(const Rendeles_Lista *lista){
    int valasz;
    fomenu_nezet();
    scanf("%d",&valasz);
    switch (valasz) {
        case 1: uj_rendeles_kezelo(lista); break;
        case 2: rendelesek_kezelo(lista);break;
        case 0: return;
        default: hibas_bemenet();
    }
}

void uj_rendeles_kezelo(const struct Rendeles_Lista *lista){
    int valasz;
    int kapott_asztalID;
    int uj_rendeles_ID=0;
    Rendeles rend;
    uj_rendeles_menu_nezet();

    scanf("%d",&valasz);

    if (valasz==0){
        fomenu_kezelo(lista);
    } else if (valasz>0&&valasz<100){
        kapott_asztalID=valasz;
        rend.asztal_id=kapott_asztalID;

        rend.id=get_legnagyobb_id();
        legnagyobb_id_novelese();



        rend.etelek=NULL;

        uj_rendeles_felvitele(&lista,&rend);

        egy_rendeles_kezelo(lista,kapott_asztalID);
    } else{
        hibas_bemenet();
    }
    return;
}

void rendelesek_kezelo(const struct Rendeles_Lista *lista){
    meglevo_rendelesek_listazasa_menu_nezet();
    //TODO: Rendelesek listazasa
    return;
}

void egy_rendeles_kezelo(const struct Rendeles_Lista *lista,int asztal_id){
    int valasz;

    rendeles_menu_nezet();

    etelekListajanakKiirasaKonzolra(rendeles_asztal_id_alapjan(lista,asztal_id)->etelek);

    scanf("%d",&valasz);

    if (valasz==1){
        etel_hozzaadas_kezelo(lista, asztal_id);
    } else if(valasz==2){
        rendeles_lezarasa_kezelo(lista,asztal_id);
    }else if(valasz==0){
        fomenu_kezelo(lista);
    }
    else{
        hibas_bemenet();
    }
    return;
}

void etel_hozzaadas_kezelo(const struct Rendeles_Lista *lista, int asztal_id){

    etlap_menu_nezet();

    etlapKiirasaKonzolra();

    int valasz;

    scanf("%d",&valasz);

    struct Etel talalt = etlaprolEtelIDAlapjan(valasz);

    hozzaadasEtelekhez(&(rendeles_asztal_id_alapjan(lista,asztal_id))->etelek,&talalt);

    printf("\n HOZZAADTAM AZ ETELT\n");
    etelekListajanakKiirasaKonzolra(lista->rendeles->etelek);

    egy_rendeles_kezelo(lista,asztal_id);
}

void rendeles_lezarasa_kezelo(const struct Rendeles_Lista *lista, int asztal_id){
    rendelesNyugta(*rendeles_asztal_id_alapjan(lista,asztal_id));
    fomenu_kezelo(lista);
    return;
}