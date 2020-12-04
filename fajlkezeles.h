#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H


void rendelesFajlbaIras(const Rendeles rend);

unsigned int etlaprolArIDAlapjan(const unsigned int id);

struct Etel etlaprolEtelIDAlapjan(const unsigned int id);

void etlaprolIDAlapjanKiiras(const unsigned int id);

void etlapKiirasaKonzolra();

void rendelesNyugta(const struct Rendeles rend);

#endif //FAJLKEZELES_H
