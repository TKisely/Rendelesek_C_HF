
#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include "rendeles.h"

void rendelesFajlbaIras(const Rendeles rend){

}

void etlaprolIDAlapjan(const unsigned int id){

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
