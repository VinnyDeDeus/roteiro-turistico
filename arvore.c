#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "ordem.h"

void Central(TCelula *x) {
    if(x != NULL) {
        Central(x -> esq);
        printf("Cidade %d\n", x -> item.cep);
        Central(x -> dir);
    }
}

void PreOrdem(TCelula *x) {
    if(x != NULL) {
        printf("Cidade %d\n", x -> item.cep);
        PreOrdem(x -> esq);
        PreOrdem(x -> dir);
    }
}

void PosOrdem(TCelula *x) {
    if(x != NULL) {
        PreOrdem(x -> esq);
        PreOrdem(x -> dir);
        printf("Cidade %d\n", x -> item.cep);
    }
}

TCelula *Pesquisar(TCelula *x, TItem Item) {
    if((x == NULL) || (x -> item.cep == Item.cep)) return x;
    if(Item.cep < x -> item.cep) return Pesquisar(x -> esq, Item);
    else if(Item.cep > x -> item.cep) return Pesquisar(x -> dir, Item);
}

TCelula *Minimo(TCelula *x) {
    if(x == NULL) return NULL;
    while(x -> esq != NULL) {
        x = x -> esq;
    }
    return x;
}

TCelula *Maximo(TCelula *x) {
    if(x == NULL) return NULL;
    while(x -> dir != NULL) {
        x = x -> dir;
    }
    return x;
}

TCelula *Sucessor(TCelula *x) {
    if(x == NULL) return NULL;
    if(x -> dir != NULL) return Minimo(x -> dir);
    TCelula *y = x -> pai;
    while(y != NULL && x == y -> dir) {
        x = y;
        y = y -> pai;
    }
    return y;
}

TCelula *Predecessor(TCelula *x) {
    if(x == NULL) return NULL;
    if(x -> esq != NULL) return Maximo(x -> esq);
    TCelula *y = x -> pai;
    while(y != NULL && x == y -> esq) {
        x = y;
        y = y -> pai;
    }
    return y;}

TCelula* criaNo(TItem Item) {
    TCelula* No = (TCelula*)malloc(sizeof(TCelula));
    No -> item = Item;
    No -> esq = NULL;
    No -> dir = NULL;
    No -> pai = NULL;
    return No;
}

void Inserir(TCelula **x, TCelula *pai, TItem Item) {
    if((*x) == NULL) {
        (*x) = criaNo(Item);
        if(pai != NULL) {
            (*x) -> pai = pai;
        }
        return;
    }
    if((*x) -> item.cep > Item.cep) {
        Inserir(&(*x) -> esq, (*x), Item);
        return;
    }
    if((*x) -> item.cep <= Item.cep) {
        Inserir(&(*x) -> dir, (*x), Item);
    }
}

// RETIRAR
void Transplante(TArvore *Arvore, TCelula **u, TCelula **v) {
    if((*u) -> pai == NULL) {
        Arvore -> raiz = (*v);
    } else if((*u) == (*u) -> pai -> esq) {
        (*u) -> pai -> esq = (*v);
    } else {
        (*u) -> pai -> dir = (*v);
    }
    if(*v != NULL) {
        (*v) -> pai = (*u) -> pai;
    }
}
void Retirar(TArvore *Arvore, TCelula **z) {
    if(*z == NULL) {
        printf("\n>>>>> AVISO: NO' \"z\" E' NULO! <<<<<\n");
        return;
    }
    if((*z) -> esq == NULL) {
        Transplante(Arvore, z, &(*z) -> dir);
    } else if((*z) -> dir == NULL) {
        Transplante(Arvore, z, &(*z) -> esq);
    } else {
        TCelula *y = Minimo((*z) -> dir);
        if(y -> pai != (*z)) {
            Transplante(Arvore, &y, &y -> dir);
            y -> dir = (*z) -> dir;
            y -> dir -> pai = y;
        }
        Transplante(Arvore, z, &y);
        y -> esq = (*z) -> esq;
        y -> esq -> pai = y;
    }
    free(*z);
    *z = NULL;
}