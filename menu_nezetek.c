#include "menu_nezetek.h"
#include <stdio.h>

void fomenu_nezet()    {
    printf(ANSI_COLOR_GREEN"\n\t\tFOMENU"ANSI_COLOR_RESET"\n");
    printf( ANSI_COLOR_MAGENTA"Kerem valasszon az alabbi menupontokbol:" ANSI_COLOR_RESET "\n\n");
    printf( ANSI_COLOR_BLUE"[1] - Uj rendeles" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_BLUE"[2] - Nyitott rendelesek" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_RED"\n[3] - Kilepes" ANSI_COLOR_RESET "\n");
}

void meglevo_rendelesek_listazasa_menu_nezet(){
    return;
}

void rendeles_eteleinek_listazasa_menu_nezet(){
    return;
}