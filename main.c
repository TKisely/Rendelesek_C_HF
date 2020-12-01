#include <stdio.h>
#include "fajlkezeles.h"

int main() {
    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=1;
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

    hozzaadasEtelekhez(&elsoRend.etelek,&elsoEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&masodikEtel);
    hozzaadasEtelekhez(&elsoRend.etelek,&harmadikEtel);

    etelKiirasKonzolra(elsoEtel);
    rendelesKiirasKonzolra(elsoRend);
    printf("=================\n");
    etelekListajanakKiirasaKonzolra(elsoRend.etelek);
    rendelesVegosszege(elsoRend.etelek);


    printf("Lefutottam\n");
    return 0;
}
