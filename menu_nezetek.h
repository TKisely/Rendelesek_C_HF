
#ifndef MENU_NEZETEK_H
#define MENU_NEZETEK_H
#include "menu_nezet_szinek.h"

void fomenu_nezet(){
    printf(ANSI_COLOR_GREEN"\n\t\tFOMENU"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem valasszon az alabbi menupontokbol:" ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_BLUE"[1] - Uj rendeles" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_BLUE"[2] - Nyitott rendelesek" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_RED"\n[3] - Kilepes" ANSI_COLOR_RESET "\n");
}

void meglevo_rendelesek_listazasa_menu_nezet(){}

void rendeles_eteleinek_listazasa_menu_nezet(){}

void uj_rendeles_menu_nezet(){}
#endif //MENU_NEZETEK_H