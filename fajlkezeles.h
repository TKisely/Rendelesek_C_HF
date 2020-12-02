
#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include "rendeles.h"
#include <string.h>
#include <time.h>

void rendelesFajlbaIras(const Rendeles rend){

}

unsigned int etlaprolArIDAlapjan(const unsigned int id){
    FILE *fajl;
    unsigned int aktID;
    unsigned int ar;
    char nev[50];
    const unsigned int maxSorhossz= 60;
    char sor[maxSorhossz];

    fajl=fopen("etlap.txt","r");
    if (fajl==NULL){
        printf("Nem sikerult az etlap megnyitasa!\n");
    } else{
        printf("Az etlap megnyilt...\n");
        while(fgets(sor,maxSorhossz,fajl)){
            sscanf(sor,"%d %s %d",&aktID,nev,&ar);
            if (aktID==id){
                return ar;
            }
        }
    }

    fclose(fajl);
}

Etel etlaprolEtelIDAlapjan(const unsigned int id){
    FILE *fajl;
    unsigned int aktID;
    unsigned int ar;
    char nev[50];
    const unsigned int maxSorhossz= 60;
    char sor[maxSorhossz];


    fajl=fopen("etlap.txt","r");
    if (fajl==NULL){
        printf("Nem sikerult az etlap megnyitasa!\n");
    } else{
        printf("Az etlap megnyilt...\n");
        while(fgets(sor,maxSorhossz,fajl)){
            sscanf(sor,"%d %s %d",&aktID,nev,&ar);
            if (aktID==id){
                Etel talalat = {aktID,"Valami",ar};
                strcpy(talalat.nev,nev);
                return talalat;
            }
        }
    }

    fclose(fajl);
}

void etlaprolIDAlapjanKiiras(const unsigned int id){
    FILE *fajl;
    unsigned int aktID;
    unsigned ar;
    char nev[50];
    int maxSorhossz= 60;
    char sor[maxSorhossz];

    fajl=fopen("etlap.txt","r");
    if (fajl==NULL){
        printf("Nem sikerult az etlap megnyitasa!\n");
    } else{
        printf("Az etlap megnyilt...\n");
        while(fgets(sor,maxSorhossz,fajl)){
            sscanf(sor,"%d %s %d",&aktID,nev,&ar);
            if (aktID==id){
                printf("\t %s \t-\t %d Ft \n",nev,ar);
            }
        }
    }

    fclose(fajl);
}

void etlapKiirasaKonzolra(){
    FILE *fajl;
    unsigned int aktID;
    unsigned ar;
    char nev[50];
    int maxSorhossz= 60;
    char sor[maxSorhossz];

    fajl=fopen("etlap.txt","r");
    if (fajl==NULL){
        printf("Nem sikerult az etlap megnyitasa!\n");
    } else{
        printf("Az etlap megnyilt...\n");
        while(fgets(sor,maxSorhossz,fajl)){
            sscanf(sor,"%d %s %d",&aktID,nev,&ar);
            printf("\t %s \t-\t %d Ft \n",nev,ar);
        }
    }

    fclose(fajl);
}

void rendelesNyugta(const struct Rendeles rend){
    FILE *fajl;
    time_t ido = time(NULL);
    struct tm tm = *localtime(&ido);
    char teljesIdo[30];
    char nyugtaCim[35];
    char fajl_neve[38];
    char fogyasztas[30];
    const struct EtelekListaja *fogyasztottEtelek=rend.etelek;

    sprintf(teljesIdo,"%d_%02d_%02d_%02d_%02d",tm.tm_year+1900, tm.tm_mon+1,tm.tm_mday,tm.tm_hour, tm.tm_min);
    sprintf(nyugtaCim,"%d__%s",rend.id,teljesIdo);
    sprintf(fajl_neve,"%s.%s",nyugtaCim,"txt");
    printf(fajl_neve);

    fajl=fopen(fajl_neve,"w");
    if (fajl==NULL){
        printf("\nSikertelen nyugta\n");
        fclose(fajl);
        return;
    }

    printf("\nNyugta megnyitva\n");

    while (fogyasztottEtelek){
        fprintf(fajl,"%s - %d\n",fogyasztottEtelek->etel->nev,fogyasztottEtelek->etel->ar);

        fogyasztottEtelek=fogyasztottEtelek->kovetkezo;
    }
    printf(fogyasztas);
    fclose(fajl);
    printf("Nyugta zarva");

}

#endif //FAJLKEZELES_H
