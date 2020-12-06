# Rendelesek_C_HF
Ez a program a Programozás alapjai 1. c. tárgy elvégzéséhez készült.

## Feladat megfogalmazása
A program feladata, hogy egy étterem rendeléseit kezelje, majd a rendelések zárásánál Nyugtát adjon.

## Alapvető funkciók listája
1. Új rendelés felvitele
2. Meglévő rendelések listázása
3. Új és meglévő rendelések szerkesztése
  * Ételek hozzáadása
  * Rendelés lezárása

## Nézetek
1. Főmenü
  * Innen érhetjük el a már meglévő rendeléseink listáját.
  * Továbbá itt kérhetjük új rendelés felvitelét.
2. Új rendelés kezelő nézet
  * Itt meg kell adnunk az új rendelés helyét (asztal id alapján).
  * Ezt követőn kész is a rendelésünk.
3. Egy rendelés kezelő nézet
  * Ez a nézet arra szolgál, hogy egy már meglévő rendelésünkön műveleteket hajtsunk végre.
  * Ide a Rendeléseket kezelő nézetből juthatunk el vagy, amennyiben új rendelést hoztunk létre automatikusan ide jutunk.
  * Ételt adhatunk a rendelésünkhöz
  * Lezarhatjuk a rendelést
4. Étlap nézet
  * Amennyiben új ételt adunk rendelésünkhöz megjelenik az Étlap nézet, ahol az ételt kiválasztva már a rendelésünkhöz és teszi a megfelelő tételt
  * Ezt követően visszajutunk a rendelés kezeléséhez
5. Meglévő rendelések kezelése
  * Minden előző rendelés it található meg
  * Az Asztal ID-t begépelve a rendelés szerkesztéséhez jutunk
  
A nézeteket színeztem, így könnyen elkülöníthetőek a megfelelő sorok az adott nézeten belül.
Emellett minden nézet rendelkezik visszalépés gombbal.

## A program felépítése
A program különböző fájlokra lett bontva:
* main.c fájl
* más .c fájlok
* .h header fájlok
* szöveges fájlok

A main.c kizárólag azért felel, hogy elindítsa a kódot és létrehozza az üres listát a később rendelések tárolására.

A tovább .c - és természetesen a hozzájuk tartozó .h fájlok - felelnek a program tényleges megvalósításáért.
* etel.c és etel.h fájlok felelnek az étel adatszerkezet megvalósításáért
* fajlkezeles.c és fajlkezeles.h fájlok felelnek elsősorban az étlappal való kapcsolatért és nyugta fájlba írásáért
* menu_kezelo.c és menu_kezelo.h fájlok felelnek a menüért, amely meghívja a tényleges funkciókhoz tartozó metódusokat, így ők biztosítják a kapcsolatot a felhasználó és a program között
* menu_nezet_szinek.h felel a színezés könnyebbé tételéért, a színek vannak benne előre definiálva
* rendeles.c és rendeles.h fájlok felelnek az egyetlen rendeléshez tartozó funkciók megvalósításáért
* rendeles_lista.c és rendeles_lista.h fájlok felelnek a rendelések listaként való kezeléséért

A szöveges fájlok két funkciót látnak el, egyrészt az etlap.txt tartalmazza az ételek listáját ( ID NÉV ÁR formátumban), míg a nyugta a program zárásakor jön létre, melynek neve az ID_ÉV_HÓNAP_NAP_ÓRA_PERC.txt formátumot követi, a tartalmát tekintve pedig rendelt ételeket árral, a végösszeget és a nyugta címéből kiolvasható adatokat.

## Adatszerkezetek
1. Étel felépítése:
```c
typedef struct Etel {
    unsigned int id;
    char nev[50];
    int ar;
} Etel;
```
2. Egy rendelés felépítése
```c
typedef struct Rendeles {
    unsigned int id;
    unsigned int asztal_id;
    struct EtelekListaja *etelek;
} Rendeles;
```

3. Ételek listába szervezése
```c
typedef struct EtelekListaja{
    struct Etel *etel;
    struct EtelekListaja *kovetkezo;
}EtelekListaja;
```

4. Rendelések listába szervezése
```c
typedef struct Rendeles_Lista {
    struct Rendeles *rendeles;
    struct Rendeles_Lista *kovetkezo;
} Rendeles_Lista;

static unsigned int LEGNAGYOBB_ID=0;
```


## Legfontosabb függvények és feladataik

## Példa sorok
#### Étlapról

1 Husleves 500

2 Gyumolcsleves 450

3 Bableves 700

4 Hamburger 1100

#### Nyugtáról

2 - Szamu rendeles		 2020_12_06_15_14-kor lezarva

Tokany 	 2500

Rizs 	 300

Bableves 	 700

Vegosszeg: 	 3500

