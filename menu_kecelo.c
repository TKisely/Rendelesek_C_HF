#include "menu_kezelo.h"
#include <stdio.h>

void fomenu_kezelo(){
    int valasz;
    fomenu_nezet();
    scanf("%d",&valasz);
    printf("%d is valasz",valasz);
    switch (valasz) {
        case 1: uj_rendeles_kezelo(); break;
        case 2: rendelesek_kezelo();break;
        case 0: return;
        default: hibas_bemenet();
    }
}

void uj_rendeles_kezelo(){
    int valasz;
    int kapott_asztalID;
    uj_rendeles_menu_nezet();

    scanf("%d",&valasz);

    if (valasz==0){
        fomenu_kezelo();
    } else if (valasz>0&&valasz<100){
        kapott_asztalID=valasz;
    } else{
        hibas_bemenet();
    }
    return;
}

void rendelesek_kezelo(){
    meglevo_rendelesek_listazasa_menu_nezet();
    //TODO: Rendelesek listazasa
    return;
}

void rendeles_kezelo(){

    return;
}