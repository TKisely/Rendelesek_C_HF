

#include <stdio.h>

#include <string.h>
#include <time.h>

#include "rendeles.h"
#include "fajlkezeles.h"
#include "menu_kezelo.h"
#include "rendeles_lista.h"
#include "etel.h"





int main() {

    Rendeles_Lista* rendelesekListaja=NULL;

    fomenu_kezelo(rendelesekListaja);

    //TODO: Hibas inputok kezelese

    printf("\n\nProgram bezarva\n");
    return 0;
}
