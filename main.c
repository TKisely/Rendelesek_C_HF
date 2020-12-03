#include <stdio.h>
#include "fajlkezeles.h"
#include "menu_nezetek.h"
#include "menu_kezelo.h"
#include "rendeles_lista.h"



int main() {
    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=LEGNAGYOBB_ID++;
    elsoRend.vegosszeg=5000;
    elsoRend.etelek=NULL;

    Rendeles masodikRend;
    masodikRend.asztal_id=5;
    masodikRend.id=LEGNAGYOBB_ID++;
    masodikRend.vegosszeg=5000;
    masodikRend.etelek=NULL;

    Rendeles_Lista* rendelesekListaja=NULL;



    Etel elsoEtel;
    elsoEtel.id=1;
    elsoEtel.ar=600;
    strcpy(elsoEtel.nev,"ELSOETEL");
    Etel masodikEtel;
    masodikEtel.id=2;
    masodikEtel.ar=450;
    strcpy(masodikEtel.nev,"MASODIKETEL");
    Etel harmadikEtel;
    harmadikEtel.id=3;
    harmadikEtel.ar=700;
    strcpy(harmadikEtel.nev,"HARMADIKETEL");
    Etel negyedik = {4,"Valami",600};

    hozzaadasEtelekhez(&elsoRend.etelek,&elsoEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&masodikEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&harmadikEtel);

    hozzaadasEtelekhez(&masodikRend.etelek,&masodikEtel);
    hozzaadasEtelekhez(&masodikRend.etelek,&harmadikEtel);

    printf("\n=================\n");
    etelekListajanakKiirasaKonzolra(elsoRend.etelek);
    rendelesVegosszege(elsoRend.etelek);
    etlapKiirasaKonzolra();
    etlaprolIDAlapjanKiiras(6);
    etlaprolIDAlapjanKiiras(11);

    printf("\n=================\n");

    printf("ITT ADOM HOZZA A RENDELESEKET");

    uj_rendeles_felvitele(&rendelesekListaja,&elsoRend);
    uj_rendeles_felvitele(&rendelesekListaja,&masodikRend);

    rendelesek_listazasa(rendelesekListaja);

    printf("\n=================\n");

    printf("%d es %d \n",etlaprolArIDAlapjan(6),etlaprolArIDAlapjan(11));

    struct Etel talalt = etlaprolEtelIDAlapjan(6);

    printf("%d %s %d\n",talalt.id,talalt.nev,talalt.ar);

//    printf("\n=================\n");
//
//    rendelesNyugta(elsoRend);
//    printf("\n=================\n");
//    rendelesNyugta(masodikRend);

    fomenu_kezelo();

    printf("\n\nLefutottam\n");
    return 0;
}
