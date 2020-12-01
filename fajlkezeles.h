
#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include "rendeles.h"
#include <string.h>

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

#endif //FAJLKEZELES_H
