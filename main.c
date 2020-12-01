#include <stdio.h>
#include "rendeles.h"

int main() {
    Rendeles elsoRend;
    elsoRend.asztal_id=5;
    elsoRend.id=1;
    elsoRend.tetelek_szama=3;
    elsoRend.vegosszeg=5000;

    rendelesKiirasKonzolra(elsoRend);
    printf("Hello, World!\n");
    return 0;
}
