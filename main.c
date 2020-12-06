

#include <stdio.h>

#include <string.h>
#include <time.h>

#include "rendeles.h"
#include "fajlkezeles.h"
#include "menu_kezelo.h"
#include "rendeles_lista.h"
#include "etel.h"





int main() {


    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=get_legnagyobb_id();
    legnagyobb_id_novelese();
    elsoRend.etelek=NULL;

    Rendeles masodikRend;
    masodikRend.asztal_id=7;
    masodikRend.id=get_legnagyobb_id();
    legnagyobb_id_novelese();
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
    //Kiirom az elso rendeles eteleit id es ar szerint
    printf("\nITT IROM KI AZ ELSO RENDELES ETELEIT\n");
    etelekListajanakKiirasaKonzolra(elsoRend.etelek);
    //Kiirom az elso rendeles vegosszeget
    rendelesVegosszege(elsoRend.etelek);

    printf("\n=================\n");

    //Kiirom az etlapot
    etlapKiirasaKonzolra();

    //Etelt irok ki id alapjan
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
//    printf("Keresett asztal szam 5");
//
//    printf("%d a megtalalt", rendeles_asztal_id_alapjan(rendelesekListaja,5).asztal_id);
//
//    etelekListajanakKiirasaKonzolra(rendeles_asztal_id_alapjan(rendelesekListaja,5).etelek);

    printf("\n=================\n");

//    rendelesNyugta(elsoRend);
//    printf("\n=================\n");
//    rendelesNyugta(masodikRend);

    printf("\nITT IROM KI AZ ID-t ASZTALID ALAPJAN\n");
    printf("%d\n",rendeles_asztal_id_alapjan(rendelesekListaja,5)->etelek->etel->ar);
    hozzaadasEtelekhez(&rendeles_asztal_id_alapjan(rendelesekListaja,5)->etelek,&masodikEtel);
    hozzaadasEtelekhez(&rendeles_asztal_id_alapjan(rendelesekListaja,5)->etelek,&masodikEtel);
    etelekListajanakKiirasaKonzolra(rendeles_asztal_id_alapjan(rendelesekListaja,5)->etelek);

    etelekListajanakKiirasaKonzolra(etelek_listaja_id_alapjan(rendelesekListaja,5));


    fomenu_kezelo(rendelesekListaja);

    printf("\n\nLefutottam\n");
    return 0;
}
