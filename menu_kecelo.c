#include <stdio.h>

#include "menu_nezetek.h"
#include "rendeles_lista.h"
#include "rendeles.h"

#include "menu_kezelo.h"


void fomenu_kezelo(const Rendeles_Lista *lista){
    int valasz;
    fomenu_nezet();
    scanf("%d",&valasz);
    printf("%d is valasz",valasz);
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

        printf("LEGNAGYOBB ID ITT %d", get_legnagyobb_id());

        rend.id=get_legnagyobb_id();
        legnagyobb_id_novelese();



        rend.etelek=NULL;

        uj_rendeles_felvitele(&lista,&rend);
        //TODO: Uj rendeles felvitele

        egy_rendeles_kezelo(lista,uj_rendeles_ID);
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

void egy_rendeles_kezelo(const struct Rendeles_Lista *lista,int id){
    rendeles_menu_nezet();

    printf("ITT EGY RENDELES KEZELO");

    rendelesek_listazasa(lista);

    printf("ITT VOLT EGY RENDELES KEZELO");
    return;
}