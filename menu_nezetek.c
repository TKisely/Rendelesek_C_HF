#include "menu_nezetek.h"
#include <stdio.h>

void fomenu_nezet()    {
    printf(ANSI_COLOR_GREEN"\n\t\tFOMENU"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem valasszon az alabbi menupontokbol:" ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_BLUE"[1] - Uj rendeles" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_BLUE"[2] - Nyitott rendelesek" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");
}

void meglevo_rendelesek_listazasa_menu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tAKTIV RENDELESEK"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem valasszon a RENDELESEK kozul:" ANSI_COLOR_RESET "\n\n");

    //TODO: Rendelesek listazasa
    printf( ANSI_COLOR_YELLOW"[1] - " ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_YELLOW"[2] - " ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");

}

void rendeles_eteleinek_listazasa_menu_nezet(){
    //TODO: Etelek listazasa
    printf( ANSI_COLOR_YELLOW"ETEL" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_YELLOW"ETEL" ANSI_COLOR_RESET "\n");
}

void rendeles_menu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tRENDELES SZERKESZTESE"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem valasszon az alabbi menupontokbol:" ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_BLUE"[1] - Etel hozzaadasa" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_BLUE"[2] - Rendeles lezarasa" ANSI_COLOR_RESET "\n");

    //TODO: Etelek listazasa
    rendeles_eteleinek_listazasa_menu_nezet();

    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");
}

void uj_rendeles_menu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tUJ RENDELES LETREHOZASA"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem adja meg az asztal szamat!" ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");
}

void rendeles_lezarasa_menu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tRENDELES LEZARVA"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"A nyugtat a rendelesi azonosito es \n a pillanatnyi ido alapjan talalhatja meg." ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");
}

void etlap_menu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tETLAP"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Az alabbi etelek kozul valaszthat:" ANSI_COLOR_RESET "\n\n");

    //TODO: Etlap listaja
    printf( ANSI_COLOR_YELLOW"ETEL" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_YELLOW"ETEL" ANSI_COLOR_RESET "\n");

    printf( ANSI_COLOR_RED"\n[0] - Kilepes" ANSI_COLOR_RESET "\n");

}

void hibas_bemenet(){
    printf(ANSI_COLOR_RED"\n\t\tHIBAS BEMENET"ANSI_COLOR_RESET"\n");
}