
#ifndef MENU_KEZELO_H
#define MENU_KEZELO_H

void uj_rendeles_kezelo(const struct Rendeles_Lista *lista);

void rendelesek_kezelo(const struct Rendeles_Lista *lista);

void fomenu_kezelo(const struct Rendeles_Lista *lista);

void egy_rendeles_kezelo(const struct Rendeles_Lista *lista,int asztal_id);

void etel_hozzaadas_kezelo(const struct Rendeles_Lista *lista, int asztal_id);

void rendeles_lezarasa_kezelo(const struct Rendeles_Lista *lista, int asztal_id);


#endif //MENU_KEZELO_H
