#include <stdio.h>
#include "fajlkezeles.h"

int main() {
    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=LEGNAGYOBB_ID++;
    elsoRend.tetelek_szama=3;
    elsoRend.vegosszeg=5000;
    elsoRend.etelek=NULL;

    Etel elsoEtel;
    elsoEtel.id=1;
    elsoEtel.ar=600;
    Etel masodikEtel;
    masodikEtel.id=2;
    masodikEtel.ar=450;
    Etel harmadikEtel;
    harmadikEtel.id=3;
    harmadikEtel.ar=700;
    Etel negyedik = {4,"Valami",600};

    hozzaadasEtelekhez(&elsoRend.etelek,&elsoEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&masodikEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&harmadikEtel);

    printf("=================\n");
    etelekListajanakKiirasaKonzolra(elsoRend.etelek);
    rendelesVegosszege(elsoRend.etelek);
    etlapKiirasaKonzolra();
    etlaprolIDAlapjanKiiras(6);
    etlaprolIDAlapjanKiiras(11);

    printf("%d es %d \n",etlaprolArIDAlapjan(6),etlaprolArIDAlapjan(11));

    struct Etel talalt = etlaprolEtelIDAlapjan(6);

    printf("%d %s %d\n",talalt.id,talalt.nev,talalt.ar);


    printf("Lefutottam\n");
    return 0;
}
