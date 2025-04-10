#ifndef _ARVORE_H
#define _ARVORE_H

#include "evento.h"

typedef struct item {
    int cep;
    Evento eventos[3];
    float media;
} TItem;

typedef struct celula {
    TItem item;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} TCelula;

typedef struct arvore {
    TCelula *raiz;
} TArvore;

void Central(TCelula *x);

void PreOrdem(TCelula *x);

void PosOrdem(TCelula *x);

TCelula *Pesquisar(TCelula *x, TItem Item);

TCelula *Minimo(TCelula *x);

TCelula *Maximo(TCelula *x);

TCelula *Sucessor(TCelula *x);

TCelula *Predecessor(TCelula *x);

// INSERIR
TCelula* criaNo(TItem Item);
void Inserir(TCelula **x, TCelula *pai, TItem Item);

// RETIRAR
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v);
void Retirar(TArvore *Arvore, TCelula **z);

#endif // _ARVORE_H