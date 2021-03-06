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
* ```etel.c``` és ```etel.h``` fájlok felelnek az étel adatszerkezet megvalósításáért
* ```fajlkezeles.c``` és ```fajlkezeles.h``` fájlok felelnek elsősorban az étlappal való kapcsolatért és nyugta fájlba írásáért
* ```menu_kezelo.c``` és ```menu_kezelo.h``` fájlok felelnek a menüért, amely meghívja a tényleges funkciókhoz tartozó metódusokat, így ők biztosítják a kapcsolatot a felhasználó és a program között
* ```menu_nezet_szinek.h``` felel a színezés könnyebbé tételéért, a színek vannak benne előre definiálva
* ```rendeles.c``` és ```rendeles.h``` fájlok felelnek az egyetlen rendeléshez tartozó funkciók megvalósításáért
* ```rendeles_lista.c``` és ```rendeles_lista.h``` fájlok felelnek a rendelések listaként való kezeléséért

A szöveges fájlok két funkciót látnak el, egyrészt az etlap.txt tartalmazza az ételek listáját (```ID NÉV ÁR``` formátumban), míg a nyugta a program zárásakor jön létre, melynek neve az ```ID_ÉV_HÓNAP_NAP_ÓRA_PERC.txt``` formátumot követi, a tartalmát tekintve pedig rendelt ételeket árral, a végösszeget és a nyugta címéből kiolvasható adatokat.

## Adatszerkezetek
1. Étel felépítése:
```c
typedef struct Etel {
    unsigned int id;
    char nev[50];
    int ar;
} Etel;
```
Minden étel tartalmaz egy egyedi azonosítót, egy nevet (maximalizálva van 50 karakterben), és egy árat.

2. Egy rendelés felépítése
```c
typedef struct Rendeles {
    unsigned int id;
    unsigned int asztal_id;
    struct EtelekListaja *etelek;
} Rendeles;
```
Minden rendelés tartalmaz egy egyedi azonosítót, egy asztal számot és a hozzá tartozó ételeinek listáját (avagy a megrendelt ételek listáját).

3. Ételek listába szervezése
```c
typedef struct EtelekListaja{
    struct Etel *etel;
    struct EtelekListaja *kovetkezo;
}EtelekListaja;
```
Ez a segéd struktúra az ételek listában való kezelését teszi lehetővé egyszeres láncolással.

4. Rendelések listába szervezése
```c
typedef struct Rendeles_Lista {
    struct Rendeles *rendeles;
    struct Rendeles_Lista *kovetkezo;
} Rendeles_Lista;
```
Ez a struktúra fugja össze a kód további struktúráit. Rendeléseket tartalmaz egyszeres láncolással, így összességében egy fésűs listáról beszélhetünk, mivel a rendelések listája listákat tartalmaz ( rendelések - ételek ).
A ```main.c``` fájlban egy, a listára mutató pointert hozunk létre, majd az egész futás alatt csak erre hivatkozva kezeljük a tárolt adatokat.


## Legfontosabb függvények és feladataik
Minden függvény esetn próbáltam a legbeszédesebb neveket kitalálni, mivel az IDE segítségével így lényegesen gyorsabban megtalálhattam a szükséges függvényeket.

### etel.h tartalma

```c
void etelKiirasKonzolra(const Etel etel);
```
Mivel alapvetően az ételeken nem szeretnénk módosítani, így azokat csak kiírnunk, vagy az étlapról felolvasnunk kell. Az utóbbi, mivel fájlból való olvasást tartalmaz, így a fájlkezeléshez került, így itt erre az egy függvényre van csak szükség.

### fajlkezeles.h tartalma

```c
void rendelesFajlbaIras(const Rendeles rend);
```
A megfelelő formázással a teljes rendelést (a rendelés által tartalmazott ételekkel együtt) a megfelelő fájlba írja.

```c
unsigned int etlaprolArIDAlapjan(const unsigned int id);

struct Etel etlaprolEtelIDAlapjan(const unsigned int id);

void etlaprolIDAlapjanKiiras(const unsigned int id);
```
Mivel az étlap nincs a programba kódolva, hanem egy külön fájl tartalmazza, emiatt minden egyes alkalommal onnan kerülnek kiolvasásra a megfelelő adatok. Ezt megtehetjük adatonként, vagy akár az egész ételt is kiírhatjuk a konzolra, vagy egy "Etel"-be csomagolva vissza is adhatjuk

```c
void etlapKiirasaKonzolra();
```
Rendelés esetén, amennyiben új ételt akarunk hozzáadni szükségünk van a teljes étlap ismeretére. Ezt az etlap.txt fájlból függvény segítségével kell kiolvasnunk.

```c
void rendelesNyugta(const struct Rendeles rend);
```
Minden egyes rendelés lezárása azzal végződik, hogy a rendelésről számla (jelen esetben egy képzeletbeli nyugta) készül. Ennek, az elkészített egyedi fájlnak a megnevezése és a tartalma is a függvény által generálódik.


### menu_kezelo.h tartalma

```c
void uj_rendeles_kezelo(const struct Rendeles_Lista *lista);

void rendelesek_kezelo(const struct Rendeles_Lista *lista);

void fomenu_kezelo(const struct Rendeles_Lista *lista);

void egy_rendeles_kezelo(const struct Rendeles_Lista *lista,int asztal_id);

void etel_hozzaadas_kezelo(const struct Rendeles_Lista *lista, int asztal_id);

void rendeles_lezarasa_kezelo(const struct Rendeles_Lista *lista, int asztal_id);
```
A main.c -ben létrehozott listát a kezelőnek átadva képesek vagyunk az összes funkciót ellátni. A Nézeteke és a kezelők természetesen külön vannak bontva.

### rendeles.h tartalma

```c
void rendelesKiirasKonzolra(const Rendeles rend);
```
Egy adott rendelés adatait írja ki a konzolra.

```c
int hozzaadasEtelekhez(struct EtelekListaja **kezd, struct Etel *ujEtel);
```
Egy rendelés étel listáját átadba hozzáadhatunk egy új rendelt ételt.

```c
int rendelesVegosszege(const struct EtelekListaja *lista);
```
Egy rendelés ételeinek listáját átadva megmondja, hogy mennyi a rendelés végösszege.

```c
void etelekListajanakKiirasaKonzolra(const struct EtelekListaja* lista);
```
Megfelelő formátumban kizrja egy rendelés ételeinek a listáját.

Mivel az utolsó 3 függvénynél csak és kizárólag az ételek listáját kezeljük, ezért felesleges átadni a teljes rendelést, emiatt meghívásukkor ügyelni kell arra, hogy ne a rendelést adjuk, hanem a ```rendeles->etelek```  listáját.

### rendeles_lista.h tartalma

```c
void uj_rendeles_felvitele(struct Rendeles_Lista **kezd,struct Rendeles *ujRendeles);
```
A rendelések listájára új rendelést visz fel.

```c
void rendelesek_listazasa(const struct Rendeles_Lista *lista);
```
Megfelelő formátumban listázza a rendeléseket.

```c
struct Rendeles* rendeles_asztal_id_alapjan(struct Rendeles_Lista *lista, unsigned int asztal_id);
```
Visszaadja a kívánt asztalhoz tartozó legfrissebb rendelést.

```c
struct EtelekListaja* etelek_listaja_id_alapjan(struct Rendeles_Lista *lista, unsigned int asztal_id);
```
Visszaadja a rendelések listájáról egy adott asztalhoz tartozó rendelés ételeinek listáját.

```c
static unsigned int LEGNAGYOBB_ID=0;

unsigned int get_legnagyobb_id();
void legnagyobb_id_novelese();
```
Mivel minden rendeléshez egyedi azonosító szükséges, ezért létre kellett hoznom egy statikus ID számláló változót, melyet a fenti függvények segítségével tudok lekérdezni és változtani.

## Példa inputok teszteléshez
A program futtatásakor a főmenü fogadja a felhasználót.

Válasszuk az új rendelés menüpontot, hisz még nincs megkezdett rendelésünk. Ehhez nyomjuk meg az 1-est a billentyűzeten (továbbiakban: ```input 1```), majd nyomjunk egy entert.

Ekkor meg kell adnunk a rendelés asztalát, vagy visszaléphetünk ```input 0``` segítségével. Mi válasszuk az asztal megadását, legyen ez a kilences asztal, tehát ```input 9```.

Ezt követően megjelenik a Rendelések szerkesztése nézet. Itt vagy lezárhatjuk a rendelést (ekkor Nyugta készül a jelenlegi állapotáról), vagy ételt adhatunk hozzá. Mivel még nincs étel a rendelésben, ezért adjunk hozzá ételeket. ```input 1```

Meglátjuk az étlapot. Válasszuk ki a Bablevest: ```input 3```

Már láthatjuk is a Rendelés szerkesztőben, hogy az aktuális rendelés tartalmaz egy Ételt, amely a 700 Ft-os Bableves.

Adjunk hozzá főételt is: ```input 1``` majd ```input 5```.

Ekkor már Borsófőzelék és Bableves is látható a rendelésben, mindig a legfrissebb tétel a lista elején.


Hozzunk létre másik rendelést is, ehhez előbb lépjünk vissza ```input 0```, majd ```input 1``` és az asztalunk legyen a négyes ```input 4```.

Adjunk hozzá pár ételt: ```input 1```, ```input 2```, ```input 1```, ```input 4```, ```input 1```, ```input 7```.

Ekkor a négyes asztalhoz tartozó rendelésünk tartalmaz egy Gyümölcslevest, egy Hamburgert és egy adag Hasábot. Ezek adatait listázza.

Lépjünk vissza egyet ```input 0```.

Listázzuk ki a Nyitott rendeléseket az ```input 2``` segítségével.

Láthatjuk, hogy két -egyedi azonosítókkal ellátott- rendelésünk van, az egyik a négyes asztalnál, a másik a kilences asztalnál.

Zárjuk le a négyes, majd a kilences rendelést is.

Ehhez előbb ```input 4```. Ekkor megnyílik a rendelésünk és láthatjuk az adatait, majd ```input 2```.

Ekkor ismét a főmenüben találjuk magunkat.

Listázzuk a rendeléseinket ```input 2```, majd a kilences asztalt megadva zárjuk a rendelést : ```input 9```, ```input 2```.

Ezt követően zárjuk a programot. ```input 0```

A két fájl megtalálható az egyedi azonosítóikkal és a zárás dátumával a fájlok között .txt formátumban.



## Példa sorok
### Étlapról

1 Husleves 500

2 Gyumolcsleves 450

3 Bableves 700

4 Hamburger 1100

### Nyugtáról

2 - Szamu rendeles		 2020_12_06_15_14-kor lezarva

Tokany 	 2500

Rizs 	 300

Bableves 	 700

Vegosszeg: 	 3500

## Egyéb információk
### Használt IDE
CLion by Jetbrains 2020.2.3 verzió.

A választásom azért esett erre az IDE-re, mert évekkel ezelőtt ezt használtam, akkor jók voltak a tapasztalataim, továbbá az általam használt OS nem tud több instance-t kezelni a VSCode-ból, amiatt a más nyelvekhez használt egyedi snippet-ek megnehezítették volna a munkám.

Sajnos - a következő fejezetben taglalt problémák miatt - nem biztos, hogy ez volt a megfelelő választás.

### Felmerült problémák
Az általam használt IDE jelenlegi verziója képtelen volt Debug módra, emiatt minden egyes hiba rengeteg időt vett el, hogy pontosan át tudjam gondolni, továbbá szintén az IDE hibájának tartom azt, hogy minden fordításnál Warning-nak jelzi a magyar nyelvből fakadó "elütéseket", így fordításnál nehéz megtalálni a tényleg fontos Warning-okat és Error-okat. 

### További teendők
A program a jelenlegi verziójában elvárja a felhasználótól, hogy megfelelő billentyűket üssön, emiatt, bár képes jelezni, ha HIBÁS bemenetet kap, lekezelni még nem tudja.
