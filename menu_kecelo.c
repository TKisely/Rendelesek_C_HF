#include "menu_kezelo.h"
#include <stdio.h>

void fomenu_kezelo(){
    int valasz;
    fomenu_nezet();
    valasz=getchar();
    switch (valasz) {
        case 1: uj_rendeles_kezelo(); break;
        case 2: rendelesek_kezelo();break;
        default: return;
    }
}

void uj_rendeles_kezelo(){return;}

void rendelesek_kezelo(){return;}