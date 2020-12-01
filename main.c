#include <stdio.h>
#include "rendeles.h"

int main() {
    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=1;
    elsoRend.tetelek_szama=3;
    elsoRend.vegosszeg=5000;

    Etel elsoEtel;
    elsoEtel.id=1;
    elsoEtel.ar=600;

    etelKiirasKonzolra(elsoEtel);
    rendelesKiirasKonzolra(elsoRend);
    printf("Hello, World!\n");
    return 0;
}
